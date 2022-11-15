#include <bits/stdc++.h>
using namespace std;
#define     pb  push_back
#define     LL  long long
#define     SZ  100005
#define     INF 1000000000000

struct node{
    int v, c;
    node(){}
    node(int _v, int _c){
        v = _v;
        c = _c;
    }
    bool operator >(const node& a)const
    {
        return c > a.c;
    }
};

priority_queue<node, vector<node>, greater<node> > pq;

vector<int> adj[SZ], cost[SZ];
LL dist[SZ];
int p[SZ];

void init(){
    for (int i = 0; i < SZ; i++){
        adj[i].clear();
        cost[i].clear();
        p[i] = 0;
        dist[i] = INF;
    }
    while (!pq.empty()) pq.pop();
}

void dijkstra(int src, int nd){
    pq.push(node(src, 0));
    dist[src] = 0;
    p[src] = src;

    while (!pq.empty()){
        node n = pq.top(); pq.pop();
        int u = n.v;

        for (int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if (dist[u] + cost[u][i] < dist[v]){
                dist[v] = dist[u] + cost[u][i];
                pq.push(node(v, dist[v]));
                p[v] = u;
            }
        }
    }

    if (dist[nd] == INF){
        printf("-1\n");
        return;
    }
    vector<int> path;
    path.pb(nd);
    int now = nd;

    while (now != src){
        now = p[now];
        path.pb(now);
    }

    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size(); i++){
        if (i > 0) printf(" ");
        printf("%d", path[i]);
    }
    printf("\n");
    path.clear();
}

int main()
{
    init();
    int T, nd, edge, c, u, v, i, j;
    scanf("%d %d", &nd, &edge);

    for (i = 1; i <= edge; i++){
        scanf("%d %d %d", &u, &v, &c);
        adj[u].pb(v);
        adj[v].pb(u);
        cost[u].pb(c);
        cost[v].pb(c);
    }
    dijkstra(1, nd);
}
