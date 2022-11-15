#include <bits/stdc++.h>
using namespace std;
#define LIM 30005
#define LL long long

LL n, ara[LIM];
vector<LL> expLeft, expRight;

void expand(LL x){
    LL tmp[n];
    for(LL i = 0; i < n; i++) tmp[i] = ara[i];
    if(x == 2) reverse(tmp, tmp+n);
    stack<LL> st;
    st.push(0);
    for(LL i = 1; i < n; i++){
        if(tmp[i] > tmp[st.top()]) st.push(i);
        else{
            while(st.size() && tmp[i] <= tmp[st.top()]){
                if(x == 1) expLeft[i] += expLeft[st.top()];
                else expRight[i] += expRight[st.top()];
                st.pop();
            }
            st.push(i);
        }
    }
    while(st.size()) st.pop();
}

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        cin>>n;
        for(LL i = 0; i < n; i++) cin>>ara[i];
        expLeft.clear();
        expRight.clear();
        for(LL i = 0; i < n; i++){
            expLeft.push_back(1);
            expRight.push_back(1);
        }
        expand(1);
        expand(2);
        reverse(expRight.begin(), expRight.end());
//        for(LL i =  0; i < n; i++) cout<<expLeft[i]<<' ';
//        cout<<'\n';
//        for(LL i =  0; i < n; i++) cout<<expRight[i]<<' ';
//        cout<<'\n';
        LL res = 0;
        for(LL i = 0; i < n; i++) res = max(res, ara[i]*(expLeft[i]+expRight[i]-1));
        printf("Case %d: %lld\n", t, res);
    }
}
/*
3
7
2 5 3 7 9 2 1 // 14
7
2 1 4 5 1 3 3 // 8
5
4 4 3 2 4 // 10
*/

