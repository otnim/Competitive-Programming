#include <bits/stdc++.h>
using namespace std;
#define LL   long long
#define pii  pair<int, int>
#define ff   first
#define ss   second
#define LIM  100000


int n, m, row, col;


int main(){
    int T; T = 1;
    for(int tc = 1; tc <= T; tc++){
        cin>>n;
        multiset<int> st;
        for(int i = 0; i < n; i++){
            st.insert(i);
        }
        auto it1 = st.begin();
        auto it = st.end()--; /// last element point korche
        it--;

        st.erase(5); /// sob 5 erase kore
        st.erase(it); /// only 'it' iterator er value erase kore
        st.erase(it1, it); /// it1-it  er sob element erase kore
        for(auto it : st) cout<<it<<' ';

        ///upper_bound -> st.upper_bound(x)/

        //cout<<st.size()<<'\n';
    }
}



