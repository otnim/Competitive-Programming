#include<bits/stdc++.h>
using namespace std;
#define X           first
#define Y           second
#define N           100005
#define pb          push_back
#define pp          pop_back
#define mk          make_pair

#define all(x)      x.begin(),x.end()
#define Sort(x)     sort(all(x))
#define mem(a,b)    memset(a,b,sizeof(a))

const int MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;

vector<pair<int,pii> > edge;
int parent[N];
int find(int r)
{
    if(parent[r]==r)return r;
    return find(parent[r]);
}
int kruskal(int n){
    sort(all(edge));
    for(int i=0;i<n;i++) parent[i]=i;
    int c=0,s=0;
    for(auto i:edge){
        int u=find(i.Y.X);
        int v=find(i.Y.Y);
        if(u!=v)
        {
            s+=i.X;
            c++;
            parent[u]=v;
            if(c==n-1)break;
        }
    }
    return s;
}
int main()
{
    int n,edg;cin>>n>>edg;
    for(int i=0;i<edg;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        edge.pb(mk(w,mk(x,y)));
    }
    cout<<kruskal(n);
}
