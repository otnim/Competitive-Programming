#include <bits/stdc++.h>
using namespace std;
#define  sortall(X)    sort(X.begin(), X.end()); // vector/string sort
#define  nl    '\n'
#define  LL    long long int
#define  pii   pair<int, int>
#define  piiii  pair<pii, pii>
#define  pb    push_back
#define  ff    first
#define  ss    second
#define  LIM   100000

int row, col, n, m, q, cnt, ara[LIM+5], ans[LIM+5], mark[LIM+5];

void add(int pos){
    if(mark[ara[pos]] == 0){
        cnt++;
    }
    mark[ara[pos]]++;
}

void del(int pos){
    mark[ara[pos]] -= 1;
    if(mark[ara[pos]] == 0) --cnt;
}

int main(){
    //freopen("ip.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T; T = 1;
    scanf("%d", &T);
    for(int tc = 1; tc <= T; tc++){
        memset(ara, 0, sizeof ara);
        memset(ans, 0, sizeof ans);
        memset(mark, 0, sizeof mark);
        cnt = 0;

        vector<piiii> v;

        scanf("%d %d", &n, &q);
        for(int i = 1; i <= n; i++) scanf("%d", &ara[i]);
        int sq = sqrt(n);
        for(int i = 1; i <= q; i++){
            int lft, rht; scanf("%d %d", &lft, &rht);
            v.pb({{lft/sq, rht}, {lft, i}});

        }
        sortall(v);
        ara[0] = ara[1];
        ara[n+1] = ara[n];
        int lft = 1, rht = 0;

        for(piiii it : v){
            int queryLft = it.ss.ff, queryRht = it.ff.ss;
            while(queryRht > rht) add(++rht);
            while(queryRht < rht) del(rht--);

            while(queryLft > lft) del(lft++);
            while(queryLft < lft) add(--lft);

            int idx = it.ss.ss;
            ans[idx] = cnt;
        }

        printf("Case %d:\n", tc);

        for(int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    }
}



