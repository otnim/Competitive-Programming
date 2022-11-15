#include <bits/stdc++.h>
using namespace std;
#define     SZ  1005

int n, cap, val[SZ], wght[SZ], dp[SZ][SZ];

int knap(int pos, int rem)
{
    if (pos < 0)
    {
        if (rem >= 0) return 0;
        return -100000000;
    }
    if (rem < 0) return -100000000;
    //if (pos < 0 || rem <= 0) return 0;

    if (dp[pos][rem] != -1) return dp[pos][rem];

    return dp[pos][rem] = max((val[pos] + knap(pos-1, rem-wght[pos])), knap(pos-1, rem));
}
int main()
{
    freopen("ip.txt", "r", stdin);

    int T; cin>>T;
    while (T--)
    {
        cin>>n>>cap;
        for (int i = 0; i < n; i++) cin>>val[i];
        for (int i = 0; i < n; i++) cin>>wght[i];

        memset(dp, -1, sizeof dp);
        int luv = knap(n-1, cap);

        cout<<"Total luv = "<<luv<<endl;

    }
}

