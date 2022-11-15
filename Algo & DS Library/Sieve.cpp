#include <bits/stdc++.h>
using namespace std;
#define mx 9999

bool prime[mx+5];
vector<int> p;
void sieve(){
    for(int i = 2; i <= mx; i++){
        for(int j = i*i; j <= mx; j += i) prime[j] = 1;
    }
    for(int i = 2; i <= mx; i++) if(prime[i] == 0) p.push_back(i);
    cout<<p.size();
    cout<<'\n';
}


int main(){
    sieve();
    cout<<p.size();



}
