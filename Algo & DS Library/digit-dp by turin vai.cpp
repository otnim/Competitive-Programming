#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long

ll a, b;
vector<int> v;
void create(ll x){
    v.clear();
    while(x){
        v.pb(x%10);
        x /= 10;
    }
    reverse(v.begin(), v.end());
}

ll dp[10][2][90];
ll fun(int idx, int f, int val){
    if(idx == v.size()) return val;
    if(dp[idx][f][val] != -1)
        return dp[idx][f][val];

    ll ans = 0, ses;

    if(f == 1) ses = 9;
    else ses = v[idx];

    for(int i=0; i<=ses; i++){
//        if(f) ans += fun(idx+1, 1, val+i);
//        else if(i != v[idx]) ans += fun(idx+1, 1, val+i);
//        else ans += fun(idx+1, 0, val+i);
        ans += fun(idx+1, f || (i!=v[idx]), val+i);
    }
    return dp[idx][f][val] = ans;
}

int main(){
    cin >> a >> b;
    create(b);
    memset(dp, -1, sizeof dp);
    ll ans = fun(0, 0, 0);
    create(a-1);
    memset(dp, -1, sizeof dp);
    ans = ans - fun(0, 0, 0);
    cout << ans<<'\n';

    return 0;
}
