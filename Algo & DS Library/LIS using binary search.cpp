 #include <bits/stdc++.h>
using namespace std;


int main()
{
    int T; cin>>T;
    while(T--){
        int i, n; cin>>n;
        vector<int> v(n);
        for(i = 0; i < n; i++) cin>>v[i];
        vector<int> t, ls; t.push_back(v[0]);
        for(i = 1; i < n; i++){
            int lo = lower_bound(t.begin(), t.end(), v[i]) - t.begin();
            ///use upper_bound for non-decreasing subsequence
            int sz = t.size();
            if(lo == sz) t.push_back(v[i]);
            else t[lo] = v[i];
        }
        cout<<t.size()<<'\n';
    }
}
//0 8 4 12 2 10 6 14 1 9 5 13 3 11 7 15
