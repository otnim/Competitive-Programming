#include <bits/stdc++.h>
using namespace std;


int main(){
    int n, r; cin>>n>>r;
    r = min(n-r, r);
    int tmp = n-r;
    vector<int> lob, hor; ///numerator, denominator
    lob.push_back(1), hor.push_back(1);
    for(int i = tmp+1; i <= n; i++) lob.push_back(i);
    for(int i = 2; i <= r; i++) hor.push_back(i);
    for(int i = 1; i < hor.size(); ){
        for(int j = 1; j < lob.size(); j++){
            int gcd = __gcd(hor[i], lob[j]);
            if(gcd > 1){
                lob[j] /= gcd;
                hor[i] /= gcd;
                if(hor[i] == 1) ++i;
                break;
            }
        }
    }
    int ans = 1;
    for(int i = 0; i < lob.size(); i++) ans *= lob[i];
    cout<<ans<<'\n';
}
