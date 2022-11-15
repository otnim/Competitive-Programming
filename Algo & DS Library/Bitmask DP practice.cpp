#include <bits/stdc++.h>
using namespace std;
#define LIM 18


int n, ara[LIM][LIM], dp[LIM][1<<LIM];
bool chkBit(int mask, int pos){return mask & (1<<pos);}
int setBit(int mask, int pos){return mask | (1<<pos);}

int f(int in, int mask){
    if(in == n) return 0;
    //if(dp[in][mask] != -1) return dp[in][mask];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!chkBit(mask, i)){
            int cur = ara[in][i] + f(in+1, setBit(mask, i));
            ans = max(ans, cur);
        }
    }
    cout<<"in = "<<in<<"  mask = "<<mask<<"  ans = "<<ans<<'\n';
    return dp[in][mask] = ans;
}

int main(){
    freopen("ip.txt", "r", stdin);
    int T; scanf("%d", &T);
    for(int t = 1; t <= T; t++){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) scanf("%d", &ara[i][j]);
        }
        memset(dp, -1, sizeof dp);

        int res = f(0, 0);
        printf("Case %d: %d\n", t, res);
    }
}


