#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define LIM 1000000


LL n, K, ara[LIM];
vector<LL> v, v2;

void allComb(LL in, LL val){
    if(val > K) return;
    v.push_back(val);
    if(in >= n/2) return;
    //cout<<"val = "<<val<<'\n';
    allComb(in+1, val);
    allComb(in+1, val+ara[in]);
    allComb(in+1, val+ara[in]*2);
}

void allComb2(LL in, LL val){
    if(val > K) return;
    v2.push_back(val);
    if(in >= n) return;
    //cout<<"val = "<<val<<'\n';
    allComb2(in+1, val);
    allComb2(in+1, val+ara[in]);
    allComb2(in+1, val+ara[in]*2);
}

int main(){
    LL T;
    scanf("%lld", &T);
    for(LL t = 1; t <= T; t++){
        scanf("%lld %lld", &n, &K);
        for(LL i = 0; i < n; i++) cin>>ara[i];

        allComb(0, 0);
        allComb2(n/2, 0);
        sort(v.begin(), v.end());
        sort(v2.begin(), v2.end());
//        cout<<'\n';
//        for(int i = 0; i < v.size();  i++) cout<<v[i]<<' ';
//        cout<<'\n';
//        cout<<'\n';
//        for(int i = 0; i < v2.size();  i++) cout<<v2[i]<<' ';
//        cout<<'\n';

        bool flag = 0;
        for(LL i = 0; i < v.size(); i++){
            LL rem = K - v[i];
            LL x = lower_bound(v2.begin(), v2.end(), rem) - v2.begin();
            if(v2[x] == rem || rem == 0) {
                flag = 1;
                break;
            }
        }
        if(flag == 1) printf("Case %lld: Yes\n", t);
        else printf("Case %lld: No\n", t);

        v.clear();
        v2.clear();
        for(LL i = 0; i < n; i++) ara[i] = 0;
    }
}


