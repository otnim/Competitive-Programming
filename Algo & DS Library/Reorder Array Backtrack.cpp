///Reorder array so that adjacent two numbers multiplication
/// is divisible by 'K' or not Backtrack, (a[i]*a[i+1])%K == 0
#include <bits/stdc++.h>
using namespace std;
#define LIM 12


int n, k, ara[LIM], isTaken[LIM];
vector<int> v;

int f(){
    if(v.size() == n) {
        for(int i = 1; i < n; i++){
            if((ara[i-1]*ara[i])%k != 0) return 0;
        }
        return 1;
    }
    for(int i = 0; i < n; i++){
        if(!isTaken[i]){
            isTaken[i] = 1;
            v.push_back(ara[i]);
            int tmp = f();
            if(tmp) return 1;
            isTaken[i] = 0;
            v.pop_back();
        }
    }
    return 0;
}

int main(){
    cin>>n>>k;
    for(int i = 0; i < n; i++) cin>>ara[i];
    v.clear();
    memset(isTaken, 0, sizeof isTaken);
    int tmp = f();
    if(tmp){
        for(int i = 0; i < n; i++) cout<<v[i]<<" ";
    }
    else cout<<"Impossible !";
    cout<<'\n';
}
