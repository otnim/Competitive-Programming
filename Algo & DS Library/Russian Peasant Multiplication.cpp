#include <bits/stdc++.h>
using namespace std;
#define uLL unsigned long long

uLL RP(uLL a, uLL b, uLL mod){
    uLL sum = 0;
    while(b > 0){
        if(b%2) sum = (sum + a) % mod;
        a = (a*2) % mod;
        b = b/2;
    }
    return sum;
}

int main(){
    uLL a, b, mod; cin>>a>>b>>mod;
    uLL res = RP(a, b, mod);

    cout<<res<<'\n';
}
