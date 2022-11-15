
#include <bits/stdc++.h>
using namespace std;
#define  LL    long long int
#define  ULL   unsigned long long int
#define  pii   pair<int, int>
#define  pLL   pair<LL, LL>
#define  pb    push_back
#define  ff    first
#define  ss    second
#define  SZ    1000055
#define  LIM   1000005
#define  base1 129
#define  base2 137
#define  mod1  1479386893
#define  mod2  1928476349
#define  mn    (int)1e-9
#define  mx    (int)1e9


string text, pat;
LL pow1[LIM], pow2[LIM], h1[LIM], h2[LIM];
LL patHash1, patHash2;
int cnt;

void calPower(){
    pow1[0] = pow2[0] = 1;
    for(int i = 1; i < LIM; i++){
        pow1[i] = (pow1[i-1]*base1)%mod1;
        pow2[i] = (pow2[i-1]*base2)%mod2;
    }
}

void preCal(){
    LL hash1 = 0, hash2 = 0;

    for(int i = 0; pat[i]; i++){
        patHash1 = ((patHash1*base1)%mod1 + (pat[i]-'a' + 1))%mod1;
        patHash2 = ((patHash2*base2)%mod2 + (pat[i]-'a' + 1))%mod2;
    }
    for(int i = 0; text[i]; i++){
        hash1 = ((hash1*base1)%mod1 + (text[i]-'a' + 1))%mod1;
        hash2 = ((hash2*base2)%mod2 + (text[i] - 'a' + 1))%mod2;
        h1[i] = hash1;
        h2[i] = hash2;
    }
    for(int i = 0; i < 3; i++) cout<<h1[1][i]<<nl;
}

void getHash(int l, int r){
    LL left1 = h1[r], left2 = h2[r];

    LL right1 = (h1[l-1]*pow1[r-l+1])%mod1;
    LL right2 = (h2[l-1]*pow2[r-l+1])%mod2;
    //cout<<(left1-right1+mod1)%mod1<<'\n';
    //cout<<(left2-right2+mod2)%mod2<<'\n';
    if((left1-right1+mod1)%mod1 == patHash1 && (left2-right2+mod2)%mod2 == patHash2) cnt++;
}

int main(){
    //freopen("ip.txt", "r", stdin);
    int T; scanf("%d", &T);
    calPower();
    for(int t = 1; t <= T; t++){
        cin>>text>>pat;
        patHash1 = patHash2 = 0;
        cnt = 0;
        preCal();
        int psz = pat.size()-1, l = 0;
        //cout<<patHash1<<' '<<patHash2<<'\n';
        for(int r = psz; text[r]; r++){
            getHash(l, r);
            l++;
        }
       printf("Case %d: %d\n", t, cnt);
    }
}

