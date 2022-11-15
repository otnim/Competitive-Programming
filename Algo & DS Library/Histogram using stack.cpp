/// LOJ - Histogram

#include <bits/stdc++.h>
using namespace std;
#define mx (int)1e9
#define LL long long

int main(){
    //freopen("in.txt", "r", stdin);
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        LL n; cin>>n;
        LL ara[n], tmp[n];
        for(LL i = 0; i < n; i++){
            cin>>ara[i];
            tmp[i] = ara[i];
        }
        vector<LL> expLeft(n, 1), expRight(n, 1);
        stack<LL> st;
        st.push(0);/// index rakchi
        expLeft[0] = expRight[0] = 1;

        for(LL i = 1; i < n; i++){
            if(ara[i] > ara[st.top()]) st.push(i);
            else{
                while(st.size() && ara[st.top()] >= ara[i]){
                    expLeft[i] += expLeft[st.top()];
                    st.pop();
                }
                st.push(i);
            }
        }
        reverse(ara, ara+n);
        while(st.size()) st.pop();
        st.push(0);
        for(LL i = 1; i < n; i++){
            if(ara[i] > ara[st.top()]) st.push(i);
            else{
                while(st.size() && ara[st.top()] >= ara[i]){
                    expRight[i] += expRight[st.top()];
                    st.pop();
                }
                st.push(i);
            }
        }
//        for(LL i = 0; i < n; i++) cout<<expLeft[i]<<' ';
//        cout<<'\n'<<'\n';
//        for(LL i = 0; i < n; i++) cout<<expRight[i]<<' ';
//        cout<<'\n';
        LL res = 0;
        reverse(expRight.begin(), expRight.end());
        for(LL i = 0; i < n; i++){
            LL range = expLeft[i] + expRight[i] - 1;
            res = max(res, tmp[i]*range);
        }
        printf("Case %d: %lld\n", t, res);
    }
}

/*
2
9
3 2 1 4 4 3 5 6 7

9
7 6 5 3 4 4 1 2 3
*/

