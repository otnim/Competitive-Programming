#include <bits/stdc++.h>
using namespace std;

#define     vi  vector<int>
#define     LIM 505
#define     pb  push_back

vi adj[LIM], cost[LIM];
bool isTaken[LIM];
int longestPath(int u){
    int ans = 0;
    for (int i = 0; i < adj[u].size(); i++){
        int v = adj[u][i], w = cost[u][i];
        if (!isTaken[v]){
            isTaken[v] = 1;
            int tmp = longestPath(v);
            cout<<"tmp = "<<tmp<<endl;
            if (ans < w + tmp){
                ans = w + tmp;
                cout<<ans<<endl<<endl;
            }
            isTaken[v] = 0;
        }
    }
    return 1;
}
int main(){
    int n, node, edge, u, v, cs;
    cin>>node>>edge;
    for (int i = 1; i <= edge; i++){
        cin>>u>>v>>cs;
        adj[u].pb(v);
        adj[v].pb(u);
        cost[u].pb(cs);
        cost[v].pb(cs);
    }
    int d = longestPath(1);
    cout<<"d = "<<d<<endl;
}

