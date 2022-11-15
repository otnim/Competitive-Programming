#include <bits/stdc++.h>
using namespace std;
#define LL long long


LL russian_peasant_multiplication(LL a, LL b, LL p){
    LL sum = 0;
    while(b > 0){
        if(b&1)  sum = (sum + a)% p;
        b >>= 1;
        a = (a << 1)% p;
    }
    return sum;
}

LL bigMod(LL a, LL d, LL p){
    if(d == 0) return 1;
    if(d == 1) return a;
    if(d&1) {
        LL x = bigMod(a, d-1, p);
        return (russian_peasant_multiplication(x, a, p))% p; /// d odd hole
    }
    LL x = bigMod(a, d/2, p);
    return (russian_peasant_multiplication(x, x, p))% p;
}

bool checkComposite(LL a, LL d, LL p, int s){
    long long x = bigMod(a, d, p);
    if(x == 1 || x == p-1) return false; /// composite noy

    for(int r = 1; r < s; r++){
        x = russian_peasant_multiplication(x, x, p)% p;
        if(x == p-1) return false;
    }
    return true;
}

bool Miller_Rabin(LL p){
    if(p == 2 || p == 3) return true;
    if(p%2 == 0 || p == 1) return false;

    int s = 0;
    LL d = p-1; /// (p-1) ke (2^s . d) format e prokash korar jonno
    while((d&1) == 0){ /// d even hole
        d >>= 1;
        s++;
    }
    vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41};
    for(int a : bases){
        if(a == p) return true;
        if(checkComposite(a, d, p, s)) return false; /// a^d % p == 1 or -1 hole probable prime hobe
    }
    return true;
}

int main(){
    int T; scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        LL p; scanf("%llu", &p);

        bool isPrime = Miller_Rabin(p);
        if(isPrime) printf("YES\n");
        else printf("NO\n");
    }
}


