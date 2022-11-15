#include <bits/stdc++.h>
using namespace std;
#define     LIM (LL)1e7
#define     mod1 147938689
#define     mod2 1928476349
#define     base 137
#define     LL long long
#define     pll pair<LL, LL>
#define     ff  first
#define     ss  second

LL h1[LIM];
LL h2[LIM];
string s;

void precal(){
    memset(h1, 0, sizeof h1);
    memset(h2, 0, sizeof h2);
    h1[0] = s[0]-'a' + 1;
    h2[0] = s[0]-'a' + 1;

    for (LL i = 1; s[i]; i++){
        h1[i] = ((h1[i-1]*base)%mod1 + s[i]-'a'+1)%mod1;
        h2[i] = ((h2[i-1]*base)%mod2 + s[i]-'a'+1)%mod2;
    }
}
void prLL(){
    for (LL i = 0; i < 6; i++) {
        cout<<h1[i]<<"     "<<h2[i]<<endl;
    }
}

pll getHash(string s2){
    int qh1 = s2[0]-'a' + 1;
    int qh2 = s2[0]-'a' + 1;
    for (LL i = 1; s2[i]; i++){
        qh1 = ((qh1*base)%mod1 + s2[i]-'a' + 1)%mod1;
        qh2 = ((qh2*base)%mod2 + s2[i]-'a' + 1)%mod2;
    }
    return {qh1, qh2};
}
int main(){
    LL i, j, k, T, q;
    cin>>s;
    precal();
    cin>>q;
    string s2;
    while (q--){
        cin>>s2;
        pll tt = getHash(s2);
        if (tt.ff == h1[3] && tt.ss == h2[3])
            cout<<"Yes, the pattern matched."<<endl;
        else cout<<"No, didn't matched."<<endl;
    }
}
