#include <bits/stdc++.h>
using namespace std;
#define LIM 100000


int time, disTime[LIM+5], finTime[LIM+5], vis[LIM+5];
vector<int> adj[LIM+5];

void dfs(int u){
    vis[u] = 1;
    for(int i = 0; i < (int)adj[u].size(); i++){
        int v = adj[u][i];
        if(vis[v]){

        }
    }
}

void d(int u){
    vis[u] = 1;
    disTime[u] = finTime[u] = time++;
    for(auto v : adj[u]){
        if(!vis[v]) d(v);
    }
}

int main(){
    int n, edge; cin>>n>>edge;
    while(edge--){
        int u, v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    d(1);
    memset(vis, 0, sizeof vis);
    dfs(1);

}

