#include <bits/stdc++.h>
using namespace std;
#define LL unsigned long long


LL dp[65][65];

LL nCr(LL n, LL r){
    if(n == r) return dp[n][r] = 1LL;
    if(r == 0LL) return dp[n][r] = 1LL;
    if(r == 1LL) return dp[n][r] = (LL)n;
    if(dp[n][r]) return dp[n][r];
    return dp[n][r] = nCr(n-1,r) + nCr(n-1,r-1);
}

int main(){
    cout<<nCr(9, 3);
}

