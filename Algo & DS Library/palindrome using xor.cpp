#include <bits/stdc++.h>
using namespace std;


int main(){
    int i, j, q, n = 26;
    string s; cin>>s>>q;
    int sz = s.size();
    int ara[n][sz];
    for(i = 0; i < n; i++){
        for(j = 0; s[j]; j++){
            if(s[j] == 'a'+i){
                ara[i][j] = 1;
            }
            else ara[i][j] = 0;
        }
    }
    for(i = 0; i < n; i++){
        for(j = 1; j < sz; j++){
            ara[i][j] ^= ara[i][j-1];
        }
    }
//    for(i = 0; i < n; i++){
//        for(j = 0; j < sz; j++){
//            cout<<ara[i][j]<<' ';
//        }cout<<'\n';
//    }
    while(q--){
        int lo, hi; cin>>lo>>hi;
        --lo, --hi;
        int cnt = 0;
        for(i = 0; i < n; i++){
            int x;
            if(lo > 0) x = ara[i][hi] ^ ara[i][lo-1];
            else x = ara[i][hi];
            if(x) {
                cnt++;
            }
        }
        if(cnt < 2) cout<<"Yes\n";
        else cout<<"No\n";
    }

}

