#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LIM 10000005

bool isPrime[LIM], segPrime[LIM];
vector<LL> prime;
LL L, R;

void sieve(){
    for(LL i = 2; i < LIM; i++){
        if(isPrime[i]) continue;
        prime.push_back(i);
        for(LL j = i*i; j < LIM; j += i){
            isPrime[j] = 1;/// 1 hole prime na
        }
    }
}

void segSieve(){
    for(LL i = 0; i < LIM; i++) segPrime[i] = 0;
    for(LL i = 0; prime[i]*prime[i] <= R; i++){
        LL base = prime[i];
        cout<<base<<'\n';
        base = (L/base)*base;
        if(base < L) base += prime[i];
        for(LL j = base; j <= R; j += prime[i])
            segPrime[j-L] = 1; /// 1 hole prime na

        if(base == prime[i]) segPrime[base-L] = 0;
    }
    for(LL i = L; i < R; i++){
        if(segPrime[i-L] == 0) cout<<i<<' ';///print 'i' as prime
    }
}

int main(){

    sieve();
    cin>>L>>R;
    segSieve();
}
