#include <bits/stdc++.h>
using namespace std;
#define LIM 100005


int ara[26][LIM], tree[26][LIM*4];

void init(int ith, int node, int st, int ed){
    if(st == ed){
        tree[ith][node] = ara[ith][st];
        return;
    }
    int left = node<<1, right = left+1, mid = (st+ed)>>1;
    init(ith, left, st, mid);
    init(ith, right, mid+1, ed);
    tree[ith][node] = tree[ith][left] + tree[ith][right];
}

int query(int ith, int node, int st, int ed, int l, int r){
    if(st > r || ed < l) return 0;
    if(st >= l && ed <= r){
        return tree[ith][node];
    }
    int left = node<<1, right = left+1, mid = (st+ed)>>1;
    int x = query(ith, left, st, mid, l, r);
    int y = query(ith, right, mid+1, ed, l, r);
    return x+y;
}

int main(){
    int i, j, q, n = 26;
    string s; cin>>s>>q;
    int sz = s.size();
    for(i = 0; i < n; i++){
        for(j = 0; s[j]; j++){
            if(s[j] == 'a'+i){
                ara[i][j+1] = 1;
            }
            else ara[i][j+1] = 0;
        }
    }
    for(i = 0; i < n; i++){
        init(i, 1, 1, sz);  ///created segment tree for each character
    }
    while(q--){
        int l, r, cnt = 0; cin>>l>>r;
        for(i = 0; i < n; i++){
            int x = query(i, 1, 1, sz, l, r);
            if(x&1) ++cnt;
        }
        if(cnt < 2) cout<<"Yes\n";
        else cout<<"No\n";
    }
}
