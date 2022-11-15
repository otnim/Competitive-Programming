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
#define  LIM   2000005
#define  base1 129
#define  base2 137
#define  mod1  147938689
#define  mod2  1928476349

int node, ara[LIM];
LL mx, mn;
int trie[LIM][2]; /// trie[a][b] := node 'a' theke 'b' hoye kothay jai
LL expo[32];

void calPower(){
    expo[0] = 1;
    for(int i = 1; i <= 31; i++){
        expo[i] = expo[i-1]*2;
    }
}

void add(int n){
    vector<int> bin;
    for(int i = 1; i <= 31; i++){
        bin.pb(n%2); /// MSB bin er seshe push hocche
        n /= 2;
    }
    int curRoot = 0;
    for(int i = bin.size()-1; i >= 0; i--){
        if(trie[curRoot][bin[i]] == -1){
            trie[curRoot][bin[i]] = ++node;
        }
        curRoot = trie[curRoot][bin[i]];
    }
}

void findMax(int n){
    int tmp = n;
    vector<int> bin;
    for(int i = 1; i <= 31; i++){
        bin.pb(n%2);
        n /= 2;
    }
    int curRoot = 0;
    LL val = 0;
    for(int i = bin.size()-1; i >= 0; i--){
        if(trie[curRoot][!bin[i]] != -1){/// ulta value niye jete parbo
            val += (!bin[i])*expo[i];
            curRoot = trie[curRoot][!bin[i]];
        }
        else{
            val += bin[i]*expo[i];
            curRoot = trie[curRoot][bin[i]];
        }
    }
    val = val^tmp;
    mx = max(mx, val);
}

void findMin(int n){
    int tmp = n;
    vector<int> bin;
    for(int i = 1; i <= 31; i++){
        bin.pb(n%2);
        n /= 2;
    }
    int curRoot = 0;
    LL val = 0;
    for(int i = bin.size()-1; i >= 0; i--){
        if(trie[curRoot][bin[i]] != -1){/// same value niye jete parbo
            val += bin[i]*expo[i];
            curRoot = trie[curRoot][bin[i]];
        }
        else{
            val += (!bin[i])*expo[i];
            curRoot = trie[curRoot][!bin[i]];
        }
    }
    val = val^tmp;
    mn = min(mn, val);
}

int main(){
    //freopen("input.txt", "r", stdin);
    int T, n; scanf("%d", &T);
    calPower();
    for(int t = 1; t <= T; t++){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++) scanf("%d", &ara[i]);
        for(int i = 2; i <= n; i++) ara[i] = ara[i-1]^ara[i];
        for(int i = 0; i < LIM; i++){
            trie[i][0] = -1;
            trie[i][1] = -1;
        }
        node = mx = 0;
        mn = INT_MAX;
        add(0);
        for(int i = 1; i <= n; i++){
            findMax(ara[i]);
            findMin(ara[i]);
            add(ara[i]);
        }
        printf("Case %d: %lld %lld\n", t, mx, mn);
    }
}
