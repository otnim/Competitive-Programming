#include <bits/stdc++.h>
using namespace std;
#define LIM 105
#define pb push_back


bool vis[LIM];
int par[LIM], mat[LIM][LIM], cap[LIM][LIM];
vector<int> path;

void bfs(int src, int sink){
    queue<int> q; q.push(src);
    memset(par, 0, sizeof par);
    vis[src] = 1;
    par[src] = src;

    while(q.size()){
        int u = q.front(); q.pop();
        for(int i = 0; i < LIM; i++){
            int v = mat[u][i];
            if(v != -1 && vis[i] == 0 && cap[u][i] > 0){
                vis[i] = 1;
                par[i] = u;
                q.push(i);
            }
        }
        if(vis[sink]) return;
    }
}

int update(){
    int mn = 10000;
    for(int i = 1; i < path.size(); i++){
        int u = path[i-1], v = path[i];
        mn = min(mn, cap[u][v]);
    }
    for(int i = 1; i < path.size(); i++){
        int u = path[i-1], v = path[i];
        cap[u][v] -= mn;
        cap[v][u] += mn;
    }
    return mn;
}

int main(){
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    int T, n, e, i, j, src, sink; scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        //cin>>n>>src>>sink>>e;
        scanf("%d %d %d %d", &n, &src, &sink, &e);
        int u, v, w;
        memset(mat, -1, sizeof mat);
        memset(cap, 0, sizeof cap);

        for(i = 1; i <= e; i++){
            //cin>>u>>v>>w;
            scanf("%d %d %d", &u, &v, &w);
            mat[u][v] = w;
            mat[v][u] = w;

            cap[u][v] += w;
            cap[v][u] += w;
        }
        int res = 0;
        while(1){
            //if(cnt > 5) break;
            //++cnt;
            memset(vis, 0, sizeof vis);
            bfs(src, sink);
            if(vis[sink] == 0) break;
            path.clear();

            int now = sink;
            while(1){
                path.pb(now);
                now = par[now];
                if(now == src){
                    path.pb(now);
                    break;
                }
            }
            reverse(path.begin(), path.end());

            int mn = update();
            res += mn;
            //for(int i = 0; i < path.size(); i++) cout<<path[i]<<' ';
            //cout<<" -> mn = "<<mn<<'\n';
        }
        //cout<<"Case "<<t<<": "<<res<<'\n';
        printf("Case %d: %d\n", t, res);
    }
}
