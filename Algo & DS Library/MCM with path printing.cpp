#include<bits/stdc++.h>
using namespace std;
#define LL     long long
#define nl     '\n'
#define pii    pair<int, int>
#define pb     push_back
#define LIM    15

int n, Next[LIM+5][LIM+5];
LL dp[LIM+5][LIM+5];
vector<pii> v;
string str;

LL fun(int lft, int rht){
    if(lft == rht) return 0LL;
    if(dp[lft][rht] != -1) return dp[lft][rht];
    LL mn = (LL)1e12;
    for(int pos = lft; pos < rht; pos++){
        LL val_1 = fun(lft, pos);
        LL val_2 = fun(pos+1, rht);
        LL curVal = v[lft].first*v[pos+1].first*v[rht].second*1LL;
        curVal += val_1 + val_2;
        if(curVal < mn){
            mn = curVal;
            Next[lft][rht] = pos;
        }
    }
    return dp[lft][rht] = mn;
}

void print(int lft, int rht){
    int pos = Next[lft][rht];
    if(lft == rht) cout<<"A"<<(lft+1);
    if(pos == -1) return;
    cout<<"(";
    print(lft, pos);
    cout<<" x ";
    print(pos+1, rht);
    cout<<")";
}

int main(){
    //freopen("ip.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T; T = 1;
    for(int tc = 1; ; tc++){
        cin>>n;
        if(!n) return 0;
        v.clear();
        memset(Next, -1, sizeof Next);
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < n; i++){
            int row, col; cin>>row>>col;
            v.pb({row, col});
        }
        fun(0, n - 1);

        printf("Case %d: ", tc);
        print(0, n-1);
        cout<<nl;
    }
}



