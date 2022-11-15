#include <bits/stdc++.h>
using namespace std;
#define LIM 110

int n, n2, ara[LIM], ara2[LIM], dp[LIM][LIM][LIM];

int f(int i, int j, int last){
    if(i >= n || j >= n2) return 0;
    if(dp[i][j][last] != -1) return dp[i][j][last];
    int ans = 0;
    if(ara[i] == ara2[j] && ara[i] > last){
        int cur = 1 + f(i+1, j+1, ara[i]);
        ans = max(ans, cur);
    }
    int cur = max(f(i+1, j, last), f(i, j+1, last));
    ans = max(ans, cur);

    return dp[i][j][last] = ans;
}

int main(){
    freopen("ip.txt", "r", stdin);
    ///array er I/P > 0 hote hobe
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>n;
        for(int i = 0; i < n; i++)cin>>ara[i];
        cin>>n2;
        for(int i = 0; i < n2; i++) cin>>ara2[i];
        memset(dp, -1, sizeof dp);
        //int lcis = f(0, 0, 0);
        int lcis = 0;
        for(int i = 0; i < n; i++){
            lcis = max(lcis, f(i, 0, ara[i]));
        }
        for(int i = 0; i < n2; i++){
            lcis = max(lcis, f(0, i, ara2[i]));
        }

        cout<<lcis+1<<'\n';
    }
}
