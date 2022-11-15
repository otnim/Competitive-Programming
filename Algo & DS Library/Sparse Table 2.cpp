#include <bits/stdc++.h>
using namespace std;
#define LIM 100005
#define LL long long


LL n, ara[LIM], sparse[LIM][16]; /// sparse[i][p] := i theke 2^p size er array er ans

void preCal(){
    for(LL i = 0; i < n; i++) sparse[i][0] = ara[i];
    for(LL p = 1; p < 16; p++){
        for(LL i = 0; i < n; i++){
            LL j = i+(1<<(p-1));
            sparse[i][p] = min(sparse[i][p-1], sparse[j][p-1]);
            if((i)<<(p-1) > n) break;
        }
    }
}

int main(){
    freopen("ip.txt", "r", stdin);
    int T; //cin>>T;
    T = 1;
    for(int t = 1; t <= T; t++){
        cin>>n;
        for(LL i = 0; i < n; i++) cin>>ara[i];
        memset(sparse, 127, sizeof sparse);
        preCal();

        LL q; cin>>q;
        while(q--){
            LL st, ed; cin>>st>>ed;
            LL mn = (LL)1e12;
            LL range = ed-st+1, idx = st;
            while(range > 0){
                LL cnt = 0, x = 1, p = 0, l = 0;
                while(1){
                    if(x<<l > range) break;
                    p++;
                    ++cnt;
                    x = x<<l;
                    l = 1;
                }
                mn = min(mn, sparse[idx][p-1]);
                idx = idx+x;
                range -= x;
                cout<<idx<<' '<<x<<' '<<range<<'\n';
            }
            cout<<mn<<'\n';
        }
    }

}



