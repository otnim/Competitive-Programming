/**     Md. Mujahedul Azad (Turin)
        Hajee Mohammad Danesh Science & Technology University **/

#include <map>
#include <math.h>
#include <cstdio>
#include <vector>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

template<class T> T gcd(T a, T b) { return (b != 0 ? gcd<T>(b, a%b) : a); }
template<class T> T lcm(T a, T b) { return (a / gcd<T>(a, b) * b); }
template<typename T> T power(T val, T p, T mod){val%=mod; T result=1; while(p>0){if(p&0x1)result=(result*val)%mod;val=(val*val)%mod;p>>=1;}return result;}
template<typename T> inline void read(T &res){
    int sign=0; res=0;
    char ch = getchar();

    while(true){
        if(ch == '-') break;
        if(ch >= '0' && ch <='9') break;
        ch = getchar();
    }

    if(ch == '-') sign = 1;
    else res = ch-'0';

    while(true){
        ch = getchar();
        if(ch < '0' || ch > '9') break;
        res = ((res<<3) + (res<<1) + (ch - '0'));
    }

    if(sign) res = 0-res;
}

#define ff                  first
#define se                  second
#define sfr(a)              read(a)
#define G()                 getchar()
#define pb                  push_back
#define pi                  acos(-1.0)
#define sq(x)               ((x) * (x))
#define sfi(x)              scanf("%d", &x)
#define sfrr(a,b)           read(a), read(b)
#define inOut               {input; output;}
#define SZ(x)               ((int) (x).size())
#define all(x)              (x).begin(), (x).end()
#define mem(a,b)            memset((a),(b),sizeof(a))
#define Case                printf("Case %d: ", cases)
#define input               freopen("input.txt","r",stdin)
#define output              freopen("output.txt","w",stdout)

#define PF                  printf
#define CASE                printf("Case %d: ", cs);
#define CASEN               printf("Case %d:\n", cs);

typedef long long ll;
typedef pair<int,int> pii;

const double eps=3e-8;
const int mx = 1e6+5;
const int MP = 3;

ll mod;
ll vcc[3];
int brr[7][mx];
int isMod[7][mx];

struct matrix{
    ll mat[3][3];
    matrix(){mem(mat,0);}
};

bool flag = false;
void getMul(const matrix &a){
    ll arr[5];
    for(int i=0; i<MP; i++){
        arr[i] =  (a.mat[i][0] * vcc[0]);
        arr[i] += (a.mat[i][1] * vcc[1]);
        arr[i] += (a.mat[i][2] * vcc[2]);
    }
    for(int i=0; i<MP; i++)
        vcc[i] = arr[i] % mod;
}

matrix multiply(const matrix &a, const matrix &b){
    matrix answer = matrix();
    for(int i=0; i<MP; i++)
    for(int j=0; j<MP; j++){
        answer.mat[i][j] = 0;
        for(int k=0; k<MP; k++)
            answer.mat[i][j] += (a.mat[i][k] * b.mat[k][j]);
        answer.mat[i][j] %= mod;
    }
    return answer;
}

#define gc getchar
#define pc putchar

//inline void CIN(ll &num){
//    num = 0; char c = gc(); ll flag = 0;
//    while(!((c>='0' && c<='9') || c=='-')) c = gc();
//    if(c == '-') flag = 1, c = gc();
//
//    while(c >= '0' && c <= '9'){
//        num = (num<<3) + (num<<1) + (c-'0');
//        c = gc();
//    }
//    if(flag) num = 0-num;
//}

matrix powerMat(matrix &m, ll n){
    matrix answer = matrix();
    answer.mat[0][0] = 1;
    answer.mat[1][1] = 1;
    answer.mat[2][2] = 1;

    while(n){
        if(n&1)
            answer = multiply(answer, m);
        m = multiply(m, m); n >>= 1;
    }
    return answer;
}

matrix mpw[65][10];
ll pw2[63];
ll pw10[10];

int main(){

    /// store for power of 2
    pw2[0] = 1;
    for(int i=1; i<63; i++)
        pw2[i] = (pw2[i-1] << 1);

    /// store for power of 10
    pw10[0] = 1;
    for(int i=1; i<10; i++)
        pw10[i] = (pw10[i-1] << 1) + (pw10[i-1] << 3);

    /// store upto 70 values
    for(int i=1; i<7; i++){
        brr[i][0] = 0; brr[i][1] = 1;
        brr[i][2] = 2; brr[i][3] = 3;
        for(int j=4; j<mx; j++){
            brr[i][j] = (brr[i][j-1]+brr[i][j-2]+brr[i][j-3]);
            if(brr[i][j] >= pw10[i]) {
                brr[i][j] %= pw10[i];
                isMod[i][j] = 1;
            }
        }
    }

    ll k = 1, vec[105];
    for(int p=1; p<=6; p++){
        mod = pw10[p]; k = 1;
        for(int i=0; i<62; i++){
            matrix mat = matrix();
            mat.mat[0][0] = 1;
            mat.mat[0][1] = 1;
            mat.mat[0][2] = 1;
            mat.mat[1][0] = 1;
            mat.mat[2][1] = 1;

            mpw[i][p] = powerMat(mat, k);
            k <<= 1;
        }
    }

    ll n, m, tc; read(tc);
    for(ll cs=1; cs<=tc; cs++){
        sfrr(n, k); PF("Case %lld: ", cs);
        if(n < mx) {
            if(isMod[k][n])
                PF("%0*d\n", (int)k, brr[k][n]);
            else PF("%d\n", brr[k][n]);
        }
        else{
            mod = pw10[k];
            matrix answer = matrix();

            int ct = 0; n -= 3;
            vcc[0] = 3; vcc[1] = 2; vcc[2] = 1;

            while(n){
                if(n&1) getMul(mpw[ct][k]);
                n >>= 1; ct++;
            }
            int ans = vcc[0] % mod;
            PF("%0*d\n", (int)k, ans);
        }
    }
    return 0;
}

