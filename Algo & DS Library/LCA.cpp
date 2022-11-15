#include <bits/stdc++.h>
using namespace std;
#define LIM 10015
#define nth 17


int n, sp[LIM][nth], par[LIM], level[LIM]; /// sp[i][p] := i theke 2^p size er array er ans
vector<int> adj[LIM];
bool vis[LIM];

void createSP(){
    for(int i = 1; i <= n; i++) sp[i][0] = i;
    for(int p = 1; p < nth; p++){
        for(int j = 1; j <= n; j++){
            sp[j][p] = sp[sp[par[j]][p-1]][p-1];
        }
    }
//    for(int p = 0; p < nth; p++){
//        for(int j = 1; j <= n; j++){
//            cout<<"sp["<<j<<"]["<<p<<"] = "<<sp[j][p]<<'\n';
//        }
//    }
}

void findLevel(int node, int lev){
    level[node] = lev;
    vis[node] = 1;
    for(int v : adj[node]) {
        if(!vis[v])findLevel(v, level[node]+1);
    }
}

int findLCA(int u, int v){
    int lev_of_u = level[u], lev_of_v = level[v];
    //if(level[u] == level[v]) return u;
    if(level[u] > level[v]){
        swap(lev_of_u, lev_of_v); ///lev_of_u <= lev_of_v    assume kore nichi
        swap(u, v);
    }
    int node = v; /// v k upore tulte hobe
    while(1){
        if(level[u] == level[v]) break;
        for(int k = 1; k < 18; k++){
            node = sp[v][k];
            if(level[u] == level[node]) {
                v = node;
                break;
            }
            if(level[node] < level[u]) {
                v = sp[v][k-1];
                break;
            }
        }
    }
    //cout<<"level = "<<level[u]<<"   "<<level[v]<<'\n';
    int nod1 = u, nod2 = v;
    while(1){
        if(u == v) return u;
        if(sp[u][1] == sp[v][1]) return sp[u][1];
        for(int k = 0; k < 18; k++){
            nod1 = sp[u][k];
            nod2 = sp[v][k];
           // cout<<"nod1 = "<<nod1<<"  nod2 = "<<nod2<<'\n';
            if(nod1 == nod2) {
                u = sp[u][k-1];
                v = sp[v][k-1];
                break;
            }
        }
    }
}

int main(){
//    freopen("ip.txt", "r", stdin);
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>n;
        for(int i = 1; i <= n; i++) par[i] = i;
        int inDeg[n+1] = {0};
        for(int i = 1; i <= n; i++){
            int x, v; cin>>x;
            while(x--){
                cin>>v;
                adj[i].push_back(v);
                par[v] = i;
                inDeg[v]++;
            }
        }
        //for(int i = 1; i <= n; i++) cout<<"par["<<i<<"] = "<<par[i]<<'\n';
        for(int i = 0; i <= n; i++) vis[i] = 0;
        int src;
        for(int i = 1; i <= n; i++) if(!inDeg[i]) src = i;
        for(int i = 1; i <= n; i++) level[i] = 0;
        findLevel(src, 0);
        //for(int i = 1; i <= n; i++) cout<<"level["<<i<<"] = "<<level[i]<<'\n';

        createSP();

        int q; cin>>q;
        printf("Case %d:\n", t);
        while(q--){
            int u, v; cin>>u>>v;
            int lca = findLCA(u, v);
            printf("%d\n", lca);
        }
        for(int i = 0; i <= n; i++) adj[i].clear();
    }
}
