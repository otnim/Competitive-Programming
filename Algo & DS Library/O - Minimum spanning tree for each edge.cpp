#include <bits/stdc++.h>
using namespace std;
#define  LL    long long int
#define  pii   pair<int, int>
#define  pb    push_back
#define  ff    first
#define  ss    second
#define  LIM   200000
#define  tpl   tuple<int, int, int>


vector<int> adj[LIM+5];
int n, root, level[LIM+5], par[LIM+5], maxSP[LIM+5][18], parSP[LIM+5][18];
int dsuPar[LIM+5], sz[LIM+5];
map<pii, int> cost;
LL mst;

void dfs(int u, int prev = -1){
    for(int v : adj[u]){
        if(v == prev) continue;
        level[v] = level[u] + 1;
        par[v] = u;
        dfs(v, u);
    }
}

void createParSP(){
    for(int i = 1; i <= n; i++) parSP[i][0] = i;
    for(int k = 1; k < 18; k++){
        for(int j = 1; j <= n; j++){
            parSP[j][k] = parSP[parSP[par[j]][k-1]][k-1];

        }
    }
}

void createSP(){
    for(int i = 1; i <= n; i++) {
        maxSP[i][0] = cost[{i, par[i]}];
    }
    //for(int i = 1; i <= n; i++) cout<<i<<"  "<<minSP[i][0]<<'\n';
    //return;
    for(int k = 1; k < 18; k++){
        for(int j = 1; j <= n; j++){
            maxSP[j][k] = max(maxSP[j][k-1], maxSP[par[parSP[j][k-1]]][k-1]);
        }
    }
    for(int i = 0; i < 18; i++){
        maxSP[root][i] = 0;
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
            node = parSP[v][k];
            if(level[u] == level[node]) {
                v = node;
                break;
            }
            if(level[node] < level[u]) {
                v = parSP[v][k-1];
                break;
            }
        }
    }
    //cout<<"level = "<<level[u]<<"   "<<level[v]<<'\n';
    int nod1 = u, nod2 = v;
    while(1){
        if(u == v) return u;
        if(parSP[u][1] == parSP[v][1]) return parSP[u][1];
        for(int k = 0; k < 18; k++){
            nod1 = parSP[u][k];
            nod2 = parSP[v][k];
           // cout<<"nod1 = "<<nod1<<"  nod2 = "<<nod2<<'\n';
            if(nod1 == nod2) {
                u = parSP[u][k-1];
                v = parSP[v][k-1];
                break;
            }
        }
    }
}

int findMax(int u, int lca){
    int node = u, lev = level[lca], mx = 0;
    int range = level[u] - lev;
    while(1){
        if(range <= 0) break;
        int cur = 0;
        for(int k = 0; k < 18; k++){
            if((1<<k) > range) break;
            cur = k;
        }
        range = range - (1<<cur);
        mx = max(mx, maxSP[u][cur]);
        u = par[parSP[u][cur]];
    }
    return mx;
}

int findPar(int u){
    if(dsuPar[u] == u) return u;
    return dsuPar[u] = findPar(dsuPar[u]);
}

void unite(int d, int u, int v){
    int p1 = findPar(u);
    int p2 = findPar(v);
    if(p1 == p2) return;
    if(p1 == u){
        dsuPar[p1] = v;
        sz[p2] += sz[p1];
    }
    else{
        dsuPar[p2] = u;
        sz[p1] += sz[p2];
    }

    mst += (1LL*d);
    //cout<<p1<<" "<<u<<"   "<<p2<<" "<<v<<"        "<<mst<<'\n';
    adj[u].push_back(v);
    if(u != root) adj[v].push_back(u);

}

int main(){
    freopen("ip.txt", "r", stdin);
    int e; scanf("%d %d", &n, &e);
    if(n == 1) return 0;
    vector<tpl> edges;

    for(int i = 0; i < e; i++){
        int u, v, len; scanf("%d %d %d", &u, &v, &len);
        cost[{u, v}] = len;
        cost[{v, u}] = len;

        edges.push_back(make_tuple(len, u, v));
    }
    for(int i = 0; i <= n; i++) {
        par[i] = dsuPar[i] = i;
        sz[i] = 1;
    }
    vector<tpl> tmp;
    tmp = edges;
    sort(edges.begin(), edges.end());
    int root = get<1>(edges[0]);
    for(tpl it : edges){
        int d = get<0>(it);
        int u = get<1>(it);
        int v = get<2>(it);
        unite(d, u, v);
    }
    dfs(root);
    createParSP();
    createSP();

    int query = e;
    for(tpl it : tmp){
        int u = get<1>(it);
        int v = get<2>(it);
        int lca = findLCA(u, v);
        //cout<<"lca = "<<lca<<"  u = "<<u<<"   v = "<<v<<'\n';
        int mx = findMax(u, lca); /// u theke lca te max
        //cout<<"mx1 = "<<mx;
        mx = max(mx, findMax(v, lca));
        //cout<<"   mx2 = "<<mx<<'\n';
        //cout<<maxSP[1][0];
        //break;
        printf("%lld\n", mst - (1LL*mx) + (1LL*get<0>(it)))<<'\n';
    }
}


