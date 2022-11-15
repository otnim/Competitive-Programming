#include <bits/stdc++.h>
using namespace std;
#define  LIM   30000

int n, ara[LIM+5], lft[LIM+5], rht[LIM+5]; /// kototuku expand kora jay

void expand(){
    for(int i = 1; i <= n; i++){
        int l = i;
        while(l > 0 && ara[l-1] >= ara[i]){
            lft[i] = lft[l-1];
            l = lft[l-1];
        }
    }
    for(int i = n; i >= 1; i--){
        int r = i;
        while(r < n && ara[r+1] >= ara[i]){
            rht[i] = rht[r+1];
            r = rht[r+1];
        }
    }
}

int main(){
    cin>>n;
    for(int i = 1; i <= n; i++) cin>>ara[i];
    for(int i = 1; i <= n; i++) lft[i] = rht[i] = i;
    expand();

    long long res = 0;
    for(int i = 1; i <= n; i++){
        int range = abs(lft[i] - i) + abs(rht[i] - i) + 1;
        res = max(res, ara[i]*range*1LL);
    }
    cout<<res<<endl;

}


