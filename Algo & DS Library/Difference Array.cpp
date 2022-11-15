/// ekta segment e maximum overlapped points count kora hoyeche
/// Differene array implementation kora hoyeche

#include <bits/stdc++.h>
using namespace std;
#define LL   long long
#define pii  pair<int, int>
#define ff   first
#define ss   second
#define LIM  400000


int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, m, row, col;
int ara[LIM+5];
LL dif[LIM+5];

int main(){
    //freopen("ip.txt", "r", stdin);
    int T; T = 1;
    //cin>>T;
    for(int tc = 1; tc <= T; tc++){
        cin>>n;
        vector<pii> v;
        set<int> points;
        for(int i = 0; i < n; i++){
            int in, out; cin>>in>>out;
            v.push_back({in, out});
            points.insert(in);
            points.insert(out);
        }
        sort(v.begin(), v.end());
        map<int, int> mp;
        int st = 1;

        for(int it : points){
            mp[it] = st++;
        }
        for(pii it : v){
            //cout<<it.ff<<" = "<<mp[it.ff]<<"   "<<it.ss<<" = "<<mp[it.ss]<<'\n';
            int lft = mp[it.ff], rht = mp[it.ss];
            dif[lft] += 1; /// (lft - rht) 1 add korte hobe
            dif[rht+1] -= 1; /// (rht - last) 1 minus korte hobe
        }
        for(int i = 1; i <= st; i++) dif[i] += dif[i-1];
        //for(int i = 1; i <= st; i++) ara[i] += dif[i-1];
        LL mx = 0;
        for(int i = 1; i <= st; i++) mx = max(mx, dif[i]);
//        for(int i = 1; i <= st; i++) cout<<ara[i]<<' ';
//        cout<<"\n\n";
//        for(int i = 1; i <= st; i++) cout<<ara[i]<<' ';
        cout<<mx<<'\n';

    }
}




