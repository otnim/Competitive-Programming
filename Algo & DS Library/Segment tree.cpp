#include <bits/stdc++.h>
using namespace std;
#define LIM 5000


int ara[LIM], tree[LIM*4];

void init(int node, int st, int ed){
    if(st == ed){
        tree[node] = ara[st];
        return;
    }
    int left = node<<1, right = left+1, mid = (st+ed)>>1;
    init(left, st, mid);
    init(right, mid+1, ed);

    tree[node] = tree[left] + tree[right];
}

void update(int node, int l, int r, int pos, int val){
    if(pos < l || pos > r) return;
    if(l == r){
        tree[node] += val;
        return;
    }
    int left = node<<1, right = left+1, mid = (l+r)>>1;
    update(left, l, mid, pos, val);
    update(right, mid+1, r, pos, val);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int l, int r, int b, int e){
    if(b > r || e < l) return 0;
    else if (l >= b && r <= e) return tree[node];

    int left = node<<1, right = left+1, mid = (l+r)>>1;

    int x = query(left, l, mid, b, e);
    int y = query(right, mid+1, r, b, e);
    return x+y;
}

int main()
{
    freopen("ip.txt", "r", stdin);
    int n, i, j; cin>>n;
    for(i = 1; i <= n; i++) cin>>ara[i];

    init(1, 1, n);
    int q; cin>>q;
    while(q--){
        int x, pos, pos2, val; cin>>x;
        if(x == 1){
            cin>>pos>>val;
            update(1, 1, n, pos, val);
        }
        else{
            cin>>pos>>pos2;
            int res = query(1, 1, n, pos, pos2);
            cout<<res<<'\n';
        }
    }
    cout<<'\n';
    for(i = 1; i <= 15; i++) cout<<tree[i]<<' ';
}

/**
input:

7
1 3 -2 5 7 2 6

7
2 1 7
1 6 -6
2 2 5
1 3 2
2 2 5
2 3 3
2 6 7

*/
