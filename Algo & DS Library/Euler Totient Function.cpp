#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>
#define LIM 1000000


LL phi[LIM+5];
bool isPrime[LIM+5];

void sievePhi(){
    for(LL i = 1; i <= LIM; i++) phi[i] = i;
    for(LL i = 2; i <= LIM; i++){
        if(isPrime[i]) continue;
        for(LL j = i+i; j <= LIM; j += i){
            isPrime[j] = 1;
            phi[j] = (phi[j]/i)*(i-1);
        }
        phi[i] = i-1;
    }
    for(int i = 1; i < 2403; i++) cout<<i<<":  "<<phi[i]<<endl;
}

int main(){
    sievePhi();
    int T; cin>>T;
    while(T--){
        LL n; cin>>n;
        cout<<phi[n]<<'\n';
    }
}




