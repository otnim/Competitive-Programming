#include <bits/stdc++.h>
using namespace std;
#define LIM 100005
#define LL long long

LL ara[LIM], tree[LIM*4], lazy[LIM*4];

void init(LL node, LL st, LL ed){
    if(st == ed){
        tree[node] = ara[st];
        return;
    }
    LL left = node<<1, right = left+1, mid = (st+ed)>>1;
    init(left, st, mid);
    init(right, mid+1, ed);

    tree[node] = tree[left] + tree[right];
}

void pushdown(LL node, LL st, LL ed){
    if(!lazy[node] || st == ed) return;
    LL left = node<<1, right = left+1, mid = (st+ed)>>1;
    LL sz1 = mid-st+1, sz2 = ed-mid;
    tree[left] += sz1*lazy[node];
    lazy[left] += lazy[node];
    tree[right] += sz2*lazy[node];
    lazy[right] += lazy[node];
    lazy[node] = 0;
}

void update(LL node, LL st, LL ed, LL l, LL r, LL val){
    pushdown(node, st, ed);
    if(st > r || ed < l) return;
    LL left = node<<1, right = left+1, mid = (st+ed)>>1;
    if(st >= l && ed <= r){
        tree[node] += (ed-st+1)*val;
        lazy[node] += val;
        return;
    }
    update(left, st, mid, l, r, val);
    update(right, mid+1, ed, l, r, val);
    tree[node] = tree[left] + tree[right];
}

LL query(LL node, LL st, LL ed, LL l, LL r){
    pushdown(node, st, ed);
    if(st > r || ed < l) return 0;
    if(st >= l && ed <= r){
        return tree[node];
    }
    LL left = node<<1, right = left+1, mid = (st+ed)>>1;
    LL x = query(left, st, mid, l, r);
    LL y = query(right, mid+1, ed, l, r);
    return x+y;
}

int main(){
    //freopen("ip.txt", "r", stdin);
    LL T; scanf("%lld", &T);
    for(LL t = 1; t <= T; t++){
        LL n, i, j; scanf("%lld", &n);
        //for(i = 1; i <= n; i++) cin>>ara[i];
        for(i = 0; i <= n; i++) ara[i] = 0;
        for(i = 0; i <= n*4; i++){
            tree[i] = 0;
            lazy[i] = 0;
        }
        init(1, 1, n);
        LL q, x, b, e, val; scanf("%lld", &q);
        printf("Case %lld:\n", t);
        while(q--){
            scanf("%lld", &x); /// 0 hole update, 1 hole query
            if(x == 0){
                scanf("%lld %lld %lld", &b, &e, &val);
                ++b, ++e;
                update(1, 1, n, b, e, val);
            }
            if(x == 1){
                scanf("%lld %lld", &b, &e);
                ++b, ++e;
                LL res = query(1, 1, n, b, e);
                printf("%lld\n", res);
            }
        }
    }
}
