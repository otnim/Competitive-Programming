/// LOJ 1179 - Josephus Problem

#include <bits/stdc++.h>
using namespace std;


int josephus(int n, int k){
    if(n == 1) return 1;

    return (josephus(n-1, k) + k - 1) % n + 1;
}

int main(){
    int T; cin>>T;
    for(int t = 1; t <= T; t++){
        int n, k; cin>>n>>k;
        int res = josephus(n, k);
        printf("Case %d: %d\n", t, res);
    }
}

