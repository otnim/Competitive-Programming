/// LOJ 1168 - Wishing Snake

#include <bits/stdc++.h>
using namespace std;
#define LIM 10050
#define pii pair<int, int>
#define ff  first
#define ss  second


bool vis[LIM];
vector<int> adj[LIM], revAdj[LIM];
stack<int> st, st2;

void dfs(int n){
    vis[n] = 1;
    for(int i : adj[n]) if(!vis[i]) dfs(i);
    st.push(n);
}

void findSCC(int n){
    vis[n] = 1;
    for(int i : revAdj[n]) if(!vis[i]) findSCC(i);
    st2.push(n);
}

void isConnected(int n){
    vis[n] = 1;
    for(int i : adj[n]) if(!vis[i]) isConnected(i);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        int n, e, u, v; cin>>n;
        set<int> nodes;
        vector<pii> edge;
        int inDeg[1005] = {0}, outDeg[1005] = {0};
        while(n--){
            int k; cin>>k;
            while(k--){
                cin>>u>>v;
                nodes.insert(u);
                nodes.insert(v);
                adj[u].push_back(v);
                revAdj[v].push_back(u);
                edge.push_back({u, v});
            }
        }
        for(int it : nodes) if(!vis[it]) dfs(it); /// SCC ber korar jonno stack e rakchi
        for(int it : nodes) vis[it] = 0;

        unordered_map<int, int> mapNode;
        for(int it : nodes) mapNode[it] = it;
        while(st.size()){
            int top = st.top(); st.pop();
            if(!vis[top]) findSCC(top);
            while(st2.size()){
                int x = st2.top(); st2.pop();
                mapNode[x] = top; /// SCC te jara ache tader same (single) node kore dichi
            }
        }
        for(auto it : edge){
            int u = mapNode[it.ff], v = mapNode[it.ss];
            if(u != v) inDeg[v]++, outDeg[u]++;
        }
        for(int it : nodes) vis[it] = 0;
        bool flag = 1; ///assuming connected
        isConnected(0);///check connected or not
        for(auto it : nodes) if(!vis[it]) flag = 0; /// flag = 0 -> not connected, as not visited

        int oddDegNode = 0, evenDegNode = 0;
        bool flag2 = 1;

        for(int it : nodes){
            int deg = inDeg[it] + outDeg[it];
            if(deg % 2 == 1) oddDegNode++;
            else if(inDeg[it] != outDeg[it]){
                flag2 = 0;/// jete parbena
                break;
            }
        }
        if(oddDegNode > 2) flag2 = 0;

        if(flag && flag2) printf("Case %d: YES\n", t);
        else printf("Case %d: NO\n", t);
        for(int i : nodes) {
            adj[i].clear();
            revAdj[i].clear();
            vis[i] = 0;
        }
        while(st2.size()) st2.pop();
        while(st.size()) st.pop();
    }
}


