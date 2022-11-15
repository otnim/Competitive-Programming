///UVa 11060
#include <bits/stdc++.h>
using namespace std;
#define     SZ  205
#define     pb  push_back

bool vis[SZ];
vector<int> adj[SZ];
map<string, int> msi;
map<int, string> mis;
int T, indeg[SZ];

void bfs(int n){
    priority_queue<int> pq;
    for (int i = 1; i <= n; i++)
        if (indeg[i] == 0) pq.push(-1*i);

    vector<int> topOrder;
    while (!pq.empty()){
        int u = -1*pq.top(); pq.pop();
        vis[u] = 1;
        topOrder.pb(u);
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            indeg[v]--;
            if (indeg[v] == 0) pq.push(-1*v);
        }
    }
    printf("Case #%d: Dilbert should drink beverages in this order:", ++T);
    for (int i = 0; i < topOrder.size(); i++)
    {
        cout<<" "<<mis[topOrder[i]];
    }
    cout<<'.'<<endl<<endl;
    topOrder.clear();
}

int main()
{
    int i, j, cnt, n, m;
    string s1, s2;
    while(scanf("%d", &n) != EOF){
        memset(indeg, 0, sizeof indeg);
        memset(vis, 0, sizeof vis);
        memset(adj, NULL, sizeof adj);
        msi.clear();
        mis.clear();

        for (i = 0, j = 0; i < n; i++){
            cin>>s1;
            ++j;
            msi[s1] = j;
            mis[j] = s1;
        }

        scanf("%d", &m);
        for (i = 0; i < m; i++){
            cin>>s1>>s2;

            adj[msi[s1]].pb(msi[s2]);
            indeg[msi[s2]]++;
        }
        bfs(n);
    }
}

