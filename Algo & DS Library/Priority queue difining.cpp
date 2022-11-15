#include <bits/stdc++.h>
using namespace std;
#define     pii pair<int, int>
#define     pb  push_back
#define     SZ  5050

struct node{
    int v, cost;

    node(int _v, int _cost){
        v = _v;
        cost = _cost;
    }

    bool operator>(const node&  a)const
    {
        return cost > a.cost;
    }
};

priority_queue<node, vector<node>, greater<node> > pq;

int main()
{
    freopen("ip.txt", "r", stdin);
    int v, cost;
    for (int i = 0; i < 5; i++) {
        cin>>v>>cost;
        //node(v, cost);
        pq.push(node(v, cost));
    }
    while (pq.size() > 0)
    {
        auto tmp = pq.top();
        cout<<"v = "<<tmp.v<<",  cost = "<<tmp.cost<<endl;
        pq.pop();
    }
}

