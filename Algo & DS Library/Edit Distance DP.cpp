#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>
#define LIM 2000


int sz, sz2, dp[LIM+5][LIM+5], vis[LIM+5][LIM+5];
string s, s2;

int f(int i, int j){
    if(i >= sz) return sz2-j;
    if(j >= sz2) return sz-i;
    if(vis[i][j]) return dp[i][j];
    vis[i][j] = 1;
    int ret = 1000000;
    if(s[i] == s2[j]) ret = f(i+1, j+1);
    else ret = 1 + min(f(i+1, j), min(f(i, j+1), f(i+1, j+1)));
    return dp[i][j] = ret;
}

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>s>>s2;
        sz = s.size();
        sz2 = s2.size();
        cout<<(f(0, 0))<<'\n';

        memset(dp, 0, sizeof dp);
        memset(vis, 0, sizeof vis);
    }
}



