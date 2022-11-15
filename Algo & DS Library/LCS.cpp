#include <bits/stdc++.h>
using namespace std;
#define LIM 500


string s1, s2, s3;
int dp[LIM][LIM];
bool vis[LIM][LIM];

int LCS(int i, int j){
    if(s1[i] == 0 || s2[j] == 0) return 0;
    if(dp[i][j]) return dp[i][j];
    if(s1[i] == s2[j]){
        return dp[i][j] = 1 + LCS(i+1, j+1);
    }
    return dp[i][j] = max(LCS(i, j+1), LCS(i+1, j));
}

int main(){
    int n;
    cin>>s1>>s2;

    int lcs = LCS(0, 0);
    cout<<lcs<<'\n';
}
