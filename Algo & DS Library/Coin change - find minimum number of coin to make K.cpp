#include<bits/stdc++.h>
using namespace std;
#define LL   long long
#define nl   '\n'
#define pii  pair<int, int>
#define pb   push_back
#define LIM  1000000


int cnt[LIM+5], freq[LIM+5];

int main(){
    //freopen("ip.txt", "r", stdin);
    int T; T = 1;
    //scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        int n; scanf("%d", &n);
        int ara[n];
        set<int> st;
        for(int i = 0; i < n; i++) {
            scanf("%d", &ara[i]);
            st.insert(ara[i]);

        }
        vector<int> vec;
        for(int it : st) vec.pb(it);
        int sz = (int)vec.size();
        int q; scanf("%d", &q);
        for(int i = 0; i < sz; i++){
            for(int j = vec[i]; j <= LIM; j += ara[i]) cnt[j]++;

        }

        while(q--){
            int x; scanf("%d", &x);
            int res = n - cnt[x];
            printf("%d\n", res);
        }
    }
}

