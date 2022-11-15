#include <bits/stdc++.h>
using namespace std;


int main(){
    int T; cin>>T;
    while(T--){
        int n, k; cin>>n>>k;
        int ara[n];
        for(int i = 0; i < n; i++) cin>>ara[i];

        deque<int> dq;
        vector<int> v;
        dq.push_front(0);///index push korchi
        int p1 = 0;
        for(int i = 1; i < n; i++){
            int st = dq.back(), ed = dq.front();
            //if(st < p1) dq.pop_back();
            while(ara[i] >= ara[ed] && dq.size()){
                dq.pop_front();
                ed = dq.front();
            }
            dq.push_front(i);

            if(i - p1 == k){
                v.push_back(ara[st]);
                p1++;
            }
            st = dq.back();
            if(i - st == k) dq.pop_back();
        }
        for(int i = 0; i < v.size(); i++) cout<<v[i]<<' ';
        cout<<ara[dq.back()];
        cout<<'\n';
        while(dq.size())dq.pop_back();
        v.clear();
    }
}
