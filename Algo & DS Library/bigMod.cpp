#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define MOD 107


LL bigMod(LL n, LL p){

    if(p == 1) return n;
    if(p == 0) return 1;
    if(p%2) {
        return (n*bigMod(n, p-1))% MOD;
    }
    LL x = bigMod(n, p/2);
    return (x*x)% MOD;
}

int main(){
    LL T; cin>>T;
    for(LL t = 1; t <= T; t++){
        LL n, p; cin>>n>>p;

        LL ans = bigMod(n, p);
        cout<<ans<<'\n';
    }
}
