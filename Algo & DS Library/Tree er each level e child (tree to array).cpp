#include <bits/stdc++.h>
using namespace std;
#define LIM 100005
#define pb  push_back

vector<int> adj[LIM];
vector<int> eachLevelChild[LIM];

int t, lev[LIM], disTime[LIM], endTime[LIM];
bool vis[LIM];

void dfs(int u){
    vis[u] = 1;
    disTime[u] = ++t;
    for(int v : adj[u]){
        if(!vis[v]){
            dfs(v);
        }
    }
    endTime[u] = ++t;
}

void bfs(int u){
    queue<int> q; q.push(u);
    vis[u] = 1;
    lev[u] = 0;
    eachLevelChild[0].pb(disTime[1]);

    while(q.size()){
        int u = q.front(); q.pop();
        for(int v : adj[u]){
            if(!vis[v]){
                vis[v] = 1;
                lev[v] = lev[u]+1;
                eachLevelChild[lev[v]].pb(disTime[v]);
                q.push(v);
            }
        }
        //cout<<" kosai"<<'\n';
    }
}

int main(){
    //freopen("in.txt", "r", stdin);
    int n, e; cin>>n;
    e = n-1;
    while(e--){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1);
    for(int i = 0; i <= n; i++) vis[i] = 0;
    bfs(1);
    //for(int i = 1; i <= n; i++){
       // cout<<"i = "<<i<<",  "<<disTime[i]<<"  "<<endTime[i]<<'\n';
   // }
//    for(int i = 0; i <= n; i++){
//        for(int j = 0; j < eachLevelChild[i].size(); j++){
//            cout<<eachLevelChild[i][j]<<"  ";
//        }cout<<'\n';
//    }
    int q; cin>>q;
    while(q--){
        int node, k; cin>>node>>k;
        int level = lev[node] + k;
        int lo = lower_bound(eachLevelChild[level].begin(), eachLevelChild[level].end(), disTime[node])-eachLevelChild[level].begin();
        int hi = upper_bound(eachLevelChild[level].begin(), eachLevelChild[level].end(), endTime[node])-eachLevelChild[level].begin();
        cout<<hi-lo<<'\n';
    }
}



