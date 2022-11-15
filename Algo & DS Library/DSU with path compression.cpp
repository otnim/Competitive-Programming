#include <bits/stdc++.h>
using namespace std;
#define LIM 1005
#define pb push_back
#define pii pair<int, int>


int sz[LIM], par[LIM];

int findPar(int u){
    if(par[u] == u) return u;
    return par[u] = findPar(par[u]);
}

void unite(int u, int v){
    u = findPar(u);
    v = findPar(v);
    if(sz[u] < sz[v]) swap(u, v);/// to get larger size, assuming sz[u] > sz[v]
    sz[u] += sz[v];
    par[v] = u;
}

int main(){
    int n, e; cin>>n;
    e = n-1;
    vector<pii> extraRoad;
    vector<int> parNode;
    for(int i = 0; i <= n; i++) par[i] = i, sz[i] = 1;
    while(e--){
        int u, v; cin>>u>>v;
        if(findPar(u) != findPar(v)) unite(u, v);
        else extraRoad.pb({u, v});
    }
    for(int i = 1; i <= n; i++) if(par[i] == i) parNode.pb(i);

    cout<<extraRoad.size()<<'\n';
    int k = 0;
    for(auto it : extraRoad){
        cout<<it.first<<" "<<it.second<<' '<<parNode[k]<<" "<<parNode[k+1]<<'\n';
        ++k;
    }
}
