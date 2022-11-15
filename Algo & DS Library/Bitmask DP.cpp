#include <bits/stdc++.h>
using namespace std;
#define LIM 17


int n, ara[LIM][LIM], dp[LIM][1<<LIM];
bool chkBit(int mask, int pos){return mask & (1<<pos);}
int setBit(int mask, int pos){return mask | (1<<pos);}

int f(int b, int mask){
    if(b == n) return 0;
    if(dp[b][mask] != -1) return dp[b][mask];
    int ans = 0;
    for(int i = 0; i < n; i++){
        if(!chkBit(mask, i)){
            int cur = ara[b][i] + f(b+1, setBit(mask, i));
            ans = max(cur, ans);
        }
    }
    return dp[b][mask] = ans;
}

int main(){
    //freopen("in.txt", "r", stdin);
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>n;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++) cin>>ara[i][j];
        }
        memset(dp, -1, sizeof dp);
        int profit = f(0, 0);
        printf("Case %d: %d\n", t, profit);
    }
}
