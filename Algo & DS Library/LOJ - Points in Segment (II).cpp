#include <bits/stdc++.h>
using namespace std;
#define LIM 500050
#define LL  long long
#define pii pair<int, int>
#define MX  100000005
#define ff  first
#define ss  second

int tree[LIM*4], lazy[LIM*4];
vector<pii> segments, newSegments, seg;
vector<int> points;
map<int, int> mp;

void modifySegment(){
    sort(points.begin(), points.end());
    sort(segments.begin(), segments.end());
    int pos = 1, lo = 0, hi, psz = points.size();

    for(int i = 0; i < psz; i++){
        pii p = {points[i], MX};
        hi = upper_bound(segments.begin()+lo, segments.end(), p) - segments.begin();
        //cout<<"lo = "<<lo<<"  hi = "<<hi<<'\n';
        for(int j = lo; j < hi; j++){
            newSegments.push_back({segments[j].ss, pos});
        }
        mp[points[i]] = pos;
        pos += 2;
        lo = hi;
    }
    sort(newSegments.begin(), newSegments.end());
    //for(int i = 0; i < newSegments.size(); i++) cout<<newSegments[i].ff<<"  "<<newSegments[i].ss<<'\n';
    int pos2 = pos + 5;
    hi = psz;
    for(int i = psz-1; i >= 0; i--){
        pii p = {points[i], -1};
        lo = lower_bound(newSegments.begin(), newSegments.end(), p) - newSegments.begin();

        for(int j = lo; j < hi; j++){
            if(newSegments[j].ss <= mp[points[i]])seg.push_back({newSegments[j].ss, mp[points[i]]});
        }
        //cout<<points[i]<<"  "<<lo<<"  "<<hi<<'\n';

        pos2 -= 2;
        hi = lo;
    }
//    for(int i = 0; i < seg.size(); i++){
//        cout<<seg[i].ff<<"  "<<seg[i].ss<<'\n';
//    }

}

void pushdown(int node, int st, int ed){
    if(!lazy[node] || st == ed) return;
    int left = node<<1, right = left+1, mid = (st+ed)>>1;
    int sz1 = mid-st+1, sz2 = ed-mid;
    tree[left] += sz1*lazy[node];
    lazy[left] += lazy[node];
    tree[right] += sz2*lazy[node];
    lazy[right] += lazy[node];
    lazy[node] = 0;
}

void update(int node, int st, int ed, int l, int r, int val){
    pushdown(node, st, ed);
    if(st > r || ed < l) return;
    int left = node<<1, right = left+1, mid = (st+ed)>>1;
    if(st >= l && ed <= r){
        tree[node] += (ed-st+1)*val;
        lazy[node] += val;
        return;
    }
    update(left, st, mid, l, r, val);
    update(right, mid+1, ed, l, r, val);
    tree[node] = tree[left] + tree[right];
}

int query(int node, int st, int ed, int l, int r){
    pushdown(node, st, ed);
    if(st > r || ed < l) return 0;
    if(st >= l && ed <= r){
        return tree[node];
    }
    int left = node<<1, right = left+1, mid = (st+ed)>>1;
    int x = query(left, st, mid, l, r);
    int y = query(right, mid+1, ed, l, r);
    return x+y;
}

int main(){
    //freopen("ip.txt", "r", stdin);
    int T; scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        int n, q, i, j; scanf("%d %d", &n, &q);
        //for(i = 1; i <= n; i++) cin>>ara[i];
        //map<pii, int> chk;
        for(i = 1; i <= n; i++) {
            int a, b; scanf("%d %d", &a, &b);
            //update(1, 0, LIM, a, b, 1);
            //if(chk[{a, b}]) continue;
            //chk[{a, b}] = 1;
            segments.push_back({a, b});
        }
        //sort(segments.begin(), segments.end());
        int x, b, e, val;
        printf("Case %d:\n", t);
        vector<int> pp;
        while(q--){
            scanf("%d", &b);
            points.push_back(b);
            pp.push_back(b);
        }
        modifySegment();
//        for(int i = 0; i < seg.size(); i++){
//            cout<<seg[i].ff<<"  "<<seg[i].ss<<'\n';}
        multiset<pii> st;
        for(pii it : seg) st.insert({it.ff, it.ss});
        for(pii it : st){
            update(1, 0, LIM, it.ff, it.ss, 1);
        }
        for(int it : pp){
            int res = query(1, 0, LIM, mp[it], mp[it]);
            //cout<<"mp[it] = "<<mp[it]<<'\n';

            printf("%d\n", res);
        }

        memset(tree, 0, sizeof tree);
        memset(lazy, 0, sizeof lazy);
        points.clear();
        segments.clear();
        newSegments.clear();
        seg.clear();
        mp.clear();

    }
}

