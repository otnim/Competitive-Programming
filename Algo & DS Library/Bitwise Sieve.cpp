#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define sz 100000000

int prime[sz/32 + 5]; /// prime[i] = 0, denotes prime

bool check(int index, int bitPos){ return bool(index & (1 << bitPos));}
int Set(int index, int bitPos){ return (index | (1 << bitPos));}

void bitwiseSieve(){
    int i, j;
    for (i = 3; i*i <= sz; i += 2){
        if (check(prime[i>>5], i & 31) == 0){
            for (j = i*i; j <= sz; j += i<<1)
                prime[j>>5] = Set(prime[j>>5], j & 31);
        }
    }
    vector<int> p;
    p.push_back(2);
    for (i = 3; i <= sz; i += 2)
        if (check(prime[i>>5], i & 31) == 0) p.push_back(i);

    for (i = 0; i < p.size(); i += 100) printf("%d\n", p[i]);
}

int main(){
    bitwiseSieve();
}

