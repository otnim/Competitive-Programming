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
        set<int> points; /// segment e jei point gulo ache tader rakhbo
        for(int i = 0; i < n; i++){
            int in, out; cin>>in>>out;
            v.push_back({in, out});
            points.insert(in);
            points.insert(out);
        }
        sort(v.begin(), v.end());
        map<int, int> mp;
        int st = 1;

        for(int it : points){ /// point guloke map kore nilam, segment compress hoye gelo
            mp[it] = st++;
        }

    }
}





