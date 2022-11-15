#include <bits/stdc++.h>
using namespace std;
#define LIM 10050

vector<int> adj[LIM];
bool cycle, vis[LIM];
int startTime[LIM], endTime[LIM];
int Time, sz;

void dfs(int u){
    startTime[u] = ++Time;
    vis[u] = 1;
    for(int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i];
        if(vis[v]){
            if(endTime[v] == 0) {
                cycle = 1;
                return;
            }
            else continue;
        }
        dfs(v);
    }
    endTime[u] = ++Time;
}


int main(){
    //freopen("ip.txt", "r", stdin);
    //freopen("op.txt", "w", stdout);
    int T, e; cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>e;
        string u, v;
        int k = 0;
        unordered_map<string, int> ump;
        for(int i = 0; i < e; i++){
            cin>>u>>v;
            if(!ump[u])ump[u] = ++k;
            if(!ump[v])ump[v] = ++k;
            adj[ump[u]].push_back(ump[v]);
        }
        Time = cycle = 0;
        for(int i = 1; i <= k; i++){
            if(!vis[i]){
                dfs(i);
            }
            if(cycle) break;
        }

        if(cycle == 0) printf("Case %d: Yes\n", t);
        else printf("Case %d: No\n", t);

        for(int i = 0; i <= k; i++) {
            adj[i].clear();
            vis[i] = 0;
            startTime[i] = 0;
            endTime[i] = 0;
        }
        ump.clear();
    }
}


