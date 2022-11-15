#include <bits/stdc++.h>
using namespace std;
#define LL   long long
#define pii  pair<int, int>
#define ff   first
#define ss   second
#define LIM  100000


int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};
int n, m, row, col;


int main(){
    //freopen("ip.txt", "r", stdin);
    int T; T = 1;
    //cin>>T;
    for(int tc = 1; tc <= T; tc++){
        cin>>n;
        vector<pii> v;
        for(int i = 1; i <= n; i++){
            int beg, ed; cin>>beg>>ed;
            v.push_back({ed, beg});
        }
        sort(v.begin(), v.end());
        int cnt = 1, overlap = 1;
        int mx = 0;
        int beg = v[0].ss, ed = v[0].ff;
        for(int i = 1; i < n; i++){
            int start = v[i].ss;
            int fin = v[i].ff;
            if(start == ed){
                cnt++;
                ed = fin;
                overlap++;
            }
            else if(start > ed){
                cnt++;
                ed = fin;
                overlap = 0;
            }
            else overlap++;

            mx = max(mx, overlap);

        }
        cout<<mx<<'\n';
    }
}


