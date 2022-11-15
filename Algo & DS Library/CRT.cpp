/// LOJ-1319 Monkey Tradition (Accepted)

#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LIM  20


LL rem[LIM+5], mod[LIM+5];

LL extended_GCD(LL a, LL b, LL &x, LL &y){
    if(b==0){
        x=1; y=0;
        return a;
    }

    LL gcd = extended_GCD(b, a%b, y, x);
    y = y - a/b * x;
    return gcd;
}

LL CRT(LL k){//mod[i] -> divisor, rem[i] -> remainder
    //calculate the size of the mod
    LL MOD = 1;
    for(int i = 0; i < k; i++) MOD *= mod[i];

    LL res = 0;
    LL x, y, m;
    for(int i = 0; i < k; i++){
        m = MOD/mod[i];
        extended_GCD(mod[i], m, x, y); // Find the solution of each group of mod[i] and m
        res = (res + y*rem[i]*MOD/mod[i] + MOD)% MOD;//Accumulate all solutions
    }
    return (res + MOD)% MOD;
}

int main(){
    int T; scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++) {
        int n; scanf("%d",&n);
        for(int i = 0; i < n; i++) scanf("%lld %lld", &mod[i], &rem[i]);

        LL res = CRT(n);
        printf("Case %d: %lld\n", tc, res);
    }
}

