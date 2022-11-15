#include <bits/stdc++.h>
using namespace std;
#define LIM 1005


int n, ara[LIM], dp[LIM][LIM];
bool vis[LIM][LIM];

int f(int in, int lastIndex){
    if(in > n) return 0;
    if(vis[in][lastIndex]) return dp[in][lastIndex];
    vis[in][lastIndex] = 1;
    int ans1 = 0, ans2 = 0;
    if(ara[in] > ara[lastIndex] && in > lastIndex) ans1 = 1 + f(in+1, in);
    ans2 = f(in+1, lastIndex);
    return dp[in][lastIndex] = max(ans1, ans2);
}

int main(){
    //freopen("ip.txt", "r", stdin);
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        memset(ara, 0, sizeof ara);
        memset(vis, 0, sizeof vis);
        cin>>n;
        for(int i = 1; i <= n; i++) cin>>ara[i];
        ara[0] = -100;
        int lis = f(1, 0);
        printf("Case %d: %d\n", t, lis);
    }
}

