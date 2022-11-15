#include <bits/stdc++.h>
using namespace std;
#define     pii pair<int, int>
#define     pb  push_back
#define     SZ  5050
#define     ff  first
#define     ss  second

int e, n, w, u, v, dist[SZ];
vector<pii> adj[SZ];

void dijkstra(int st, int term)
{
    memset(dist, 127, sizeof dist);
    priority_queue<pii> pq;
    dist[st] = 0;
    pq.push({-dist[st], st});

    while (!pq.empty()){
        auto tmp = pq.top(); pq.pop();
        int d = -tmp.ff, curNode = tmp.ss;

        for (auto tt : adj[curNode]){
            int to = tt.ff, d2 = tt.ss;

            if (d + d2 < dist[to]){
                dist[to] = d + d2;
                pq.push({-dist[to], to});
            }
        }
    }
    for (int i = 0; i < n; i++) cout<<"dist["<<i<<"] =  "<<dist[i]<<endl;
}

int main(){
    freopen("ip.txt", "r", stdin);
    int T; cin>>T;
    while (T--){
        cin>>n>>e;
        for(int i = 0; i < e; i++){
            cin>>u>>v>>w;
            adj[u].pb({v, w});
            adj[v].pb({u, w});
        }
        int term; cin>>term;
        dijkstra(0, term);
    }
}
