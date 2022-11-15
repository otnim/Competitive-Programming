#include<bits/stdc++.h>
using namespace std;
#define LL     long long
#define nl     '\n'
#define pii    pair<int, int>
#define piiii  pair<pii, pii>
#define piiL   pair<pii, LL>
#define pb     push_back
#define LIM    15

int n;
piiL dp[LIM+5][LIM+5];
vector<pii> v;
int Next[LIM+5][LIM+5];
string str;

piiL fun(int lft, int rht){
    if(rht - lft == 0){
        int row = v[lft].first;
        int col = v[lft].second;
        return {{row, col}, 0LL};
    }
    if(dp[lft][rht] != make_pair(make_pair(-1, -1), -1LL)) return dp[lft][rht];
    LL mn = (LL)1e12;
    int retRow, retCol;
    for(int pos = lft; pos < rht; pos++){
        piiL lftValue = fun(lft, pos);
        piiL rhtValue = fun(pos+1, rht);
        int row = lftValue.first.first;
        int mid = lftValue.first.second;
        int col = rhtValue.first.second;
        LL val_1 = lftValue.second;
        LL val_2 = rhtValue.second;
        LL curVal = row*mid*col*1LL + val_1 + val_2;
        //cout<<"curValue = "<<curVal<<nl;
        //cout<<"row = "<<row<<"  mid = "<<mid<<"  col = "<<col<<nl;
        if(curVal < mn){
            mn = curVal;
            retRow = row;
            retCol = col;
            Next[lft][rht] = pos;
        }
    }
    //cout<<retRow<<"  "<<retCol<<nl;
    return dp[lft][rht] = {{retRow, retCol}, mn};
}

void print(int lft, int rht){
    int pos = Next[lft][rht];
    if(pos == -1) return;
    print(lft, pos);
    print(pos+1, rht);
    //cout<<lft<<"  "<<rht<<nl;
    ++lft, ++rht;
    if(rht == 10) rht = 0;
    for(int i = 0; str[i]; i++){
        if(str[i]-'0' == lft) {
            str.insert(i-1, "(");
            break;
        }
    }
    for(int i = 0; str[i]; i++){
        if(str[i]-'0' == rht){
            str.insert(i+1, ")");
            break;
        }
    }
}

int main(){
//    freopen("ip.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
    int T; T = 1;
    for(int tc = 1; ; tc++){
        cin>>n;
        if(!n) return 0;
        v.clear();
        memset(Next, -1, sizeof Next);
        for(int i = 0; i <= LIM; i++){
            for(int j = 0; j <= LIM; j++) dp[i][j] = {{-1, -1}, -1LL};
        }
        for(int i = 0; i < n; i++){
            int row, col; cin>>row>>col;
            v.pb({row, col});
        }

        piiL res = fun(0, n - 1);

        printf("Case %d: ", tc);
        str = "";
        for(int i = 1; i <= n && i < 10; i++){
            if(i > 1) str += " x ";
            char ch = char(i + 48);
            //cout<<ch<<nl;
            str = str + "A" + ch;
        }
        if(n == 10) str = str + " x A10";
        print(0, n-1);
        cout<<str<<nl;

        //cout<<res.first.first<<"   "<<res.first.second<<nl;
        //cout<<"Total Operation = "<<res.second<<nl;
    }
}


