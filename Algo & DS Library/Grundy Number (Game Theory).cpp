#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>
#define LIM 15

int fib[40], mex[LIM+5];

void fibonacci(){
    fib[0] = 1, fib[1] = 1;
    for(int i = 2; i < 40-5; i++){
        if(fib[i-1] + fib[i-2] > 3000000) break;
        fib[i] = fib[i-1] + fib[i-2]; /// 32 ta hobe
    }
}

void calMex(){
    mex[0] = 0;
    for(int i = 1; i < LIM; i++){
        set<int> grundy;
        for(int j = 1;  j< 33; j++){
            if(i >= fib[j]){
                grundy.insert(mex[i-fib[j]]);
                //cout<<"in " <<grundy.size()<<'\n';
            }
        }
        int mn = 0;
        auto it = grundy.begin();
        if(i == 4) cout<<*it<<'\n';
        while(it != grundy.end()){
            if(*it != mn) break;
            mn++;
            it++;
        }
        mex[i] = mn;
        //cout<<mn<<' ';
    }
    for(int i = 0; i < 12; i++) cout<<mex[i]<<' ';
//    if(xr) cout<<"Ada\n";
//    else cout<<"Vinit\n";
}

int main(){
    fibonacci();
    int n; cin>>n;
    int ara[n];
    for(int i = 0; i < n; i++) cin>>ara[i];
    calMex();
}



