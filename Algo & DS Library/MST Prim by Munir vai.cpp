#include<bits/stdc++.h>
using namespace std;
#define ff           first
#define ss           second
#define N           41
#define pb          push_back
#define pp          pop_back
#define mk          make_pair

const int MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<char,int> pci;

vector<pii>e[N];
bool vis[N];
int prims()
{
    priority_queue<pii>p;
    p.push(mk(0,1));
    int mst_cost=0;
    while(!p.empty())
    {
        pii t=p.top();p.pop();
        int node=t.ss,cost=-t.ff;
        if(vis[node])continue;
        mst_cost+=cost;
        vis[node]=1;
        for(int i=0;i<e[node].size();i++)
        {
            pii u=e[node][i];
            if(!vis[u.ss])p.push(mk(-u.ff,u.ss));
        }
    }
    return mst_cost;
}

int main()
{
    freopen("ip.txt", "r", stdin);
    int n,edg;cin>>n>>edg;
    for(int i=0;i<edg;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        e[x].pb(mk(w,y));
        e[y].pb(mk(w,x));
    }
    cout<<prims();
     return 0;
}
