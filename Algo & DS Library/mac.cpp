#include <bits/stdc++.h>
using namespace std;
#define  fread ios_base::sync_with_stdio(false); cin.tie(NULL);
#define  nl    '\n'
#define  LL    long long int
#define  ULL   unsigned long long int
#define  pii   pair<int, int>
#define  piii  pair<pii, int>
#define  pLL   pair<LL, LL>
#define  pb    push_back
#define  ff    first
#define  ss    second
#define  mod   147938689
#define  mod2  1928476349
#define  MN    (int)1e-9
#define  MX    (int)1e9
#define  base  129
#define  base2 137
#define  LIM   100000

// Direction Array
int dr[] = {0, -1, 0, 1}; /// Right, Up, Left, Bottom direction
int dc[] = {1, 0, -1, 0};
int dr8[] = {0, -1, 0, 1, -1, -1, 1, 1}; /// 1st 4ta -> Right, Up, Left, Bottom,
int dc8[] = {1, 0, -1, 0, 1, -1, -1, 1}; /// 2nd 4ta -> up-right, up-left, bottom-left, bottom-right direction
int kx[] = {-1, -2, -2, -1, 1, 2, 2, 1}; /// knight moves
int ky[] = {2, 1, -1, -2, -2, -1, 1, 2};
// Bitwise Operation
bool chkBit(int mask, int pos){return mask & (1<<pos);}
int setBit(int mask, int pos){return mask | (1<<pos);}
int row, col, n, m;

bool isValid(int r, int c){
    return (r >= 0 && r < row && c >= 0 && c < col);
}

int main(){
    int T; T = 1;
    //cin>>T;
    for(int tc = 1; tc <= T; tc++){

















    }
}





