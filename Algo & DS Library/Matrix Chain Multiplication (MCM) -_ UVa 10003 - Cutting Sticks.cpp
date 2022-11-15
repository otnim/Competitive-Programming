#include <bits/stdc++.h>
using namespace std;
#define LIM 55


int ara[LIM], dp[LIM][LIM];

int MCM(int l, int r){
    if(r-l <= 1) return 0;
    if(dp[l][r] != -1) return dp[l][r];
    int ans = INT_MAX;
    for(int i = l+1, k = 0; i < r; i++, k++){
        int len = ara[r] - ara[l];
        ans = min(ans, len + MCM(l, i) + MCM(i, r));
    }
    return dp[l][r] = ans;
}

int main(){
    //freopen("ip.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int len, n;
    while(1){
        scanf("%d", &len);
        if(len == 0) break;
        scanf("%d", &n);
        ara[0] = 0;
        for(int i = 1; i <= n; i++) scanf("%d", &ara[i]);
        n++;
        ara[n] = len;
        memset(dp, -1, sizeof dp);
        int ans = MCM(0, n);

        printf("The minimum cutting is %d.\n", ans);
    }
}


