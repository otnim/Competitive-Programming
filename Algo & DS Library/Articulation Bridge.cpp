#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>
#define LIM 700
#define ff  first
#define ss  second

vector<int> adj[LIM+5];
int tme, n, m, vis[LIM+5], dis[LIM+5], low[LIM+5], par[LIM+5];
vector<pii> bridges;

void dfs(int u, int p){
    vis[u] = 1;
    dis[u] = low[u] = ++tme;
    for(int v : adj[u]){
        if(v == p) continue;
        if(!vis[v]){
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if(dis[u] < low[v]){
                int a = u, b = v;
                if(a > b) swap(a, b);
                bridges.push_back({a, b});
            }
        }
        else low[u] = min(low[u], dis[v]);
    }
}

int main(){
    //freopen("ip.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T; scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        tme = 0;
        scanf("%d %d", &n, &m);
        for(int i = 0; i <= LIM; i++) {
            dis[i] = vis[i] = par[i] = low[i] = 0;
            adj[i].clear();
        }
        bridges.clear();
        for(int i = 0; i < m; i++){
            int u, v; scanf("%d %d", &u, &v);
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i = 1; i <= n; i++) par[i] = -1;
        dfs(1, -1);

        sort(bridges.begin(), bridges.end());
        if(!bridges.size()) {
            printf("Caso #%d\nSin bloqueos\n", t);
            continue;
        }
        printf("Caso #%d\n%d\n", t, bridges.size());
        for(pii it : bridges) printf("%d %d\n", it.ff, it.ss);
        for(int i = 0; i <= LIM; i++) {
            dis[i] = vis[i] = par[i] = low[i] = 0;
            adj[i].clear();
        }
        bridges.clear();
        //cout<<"..................\n";
    }
}

