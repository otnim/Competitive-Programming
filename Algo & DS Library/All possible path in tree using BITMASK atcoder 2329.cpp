#include <bits/stdc++.h>
using namespace std;
#define LIM 17


int n, e, dp[LIM][1<<LIM];
vector<int> adj[LIM];
bool chkBit(int mask, int pos){return mask & (1<<pos);}
int setBit(int mask, int pos){return mask | (1<<pos);}

int f(int u, int mask){
    if(__builtin_popcount(mask) == n-1) {
        //cout<<mask<<'\n';
        return 1;
    }
    if(dp[u][mask] != -1) return dp[u][mask];
    int ans = 0;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(!chkBit(mask, v)){
            ans += f(v, setBit(mask, u));
        }
    }
    return dp[u][mask] = ans;
}

int main(){
    //freopen("ip.txt", "r", stdin);
    int T; T = 1;// cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>n>>e;
        for(int i = 0; i < e; i++){
            int u, v; cin>>u>>v;
            --u, --v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        memset(dp, -1, sizeof dp);
        int cntPath = f(0, 0);
        //printf("Case %d: %d\n", t, cntPath);
        printf("%d\n", cntPath);
        for(int i = 0; i < n; i++) adj[i].clear();
    }
}


