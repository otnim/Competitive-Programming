#include <bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define ff first
#define ss second
#define sfi(a) scanf("%d",&a)
#define sfi2(a,b) scanf("%d %d",&a,&b)
#define sfi3(a,b,c) scanf("%d %d %d",&a,&b,&c)
#define sfll(a) scanf("%lld",&a)
#define inf 1e15
#define m_p make_pair
#define min3(a,b,c) min(a,min(b,c))
#define pb push_back
#define mem(x,val) memset(x,val,sizeof(x))
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define FAST  ios_base::sync_with_stdio(0);cout.tie(0)
#define sqr(x) ((x)*(x))

typedef long long ll;
const ll mod = 100000007;
const int sz = 2;

void read_matrix(int arr[sz][sz]){
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            sfi(arr[i][j]);
        }
    }
}

void result_mat(int A[sz][sz],int B[sz][sz]){
    int C[sz][sz]; mem(C,0);
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            int row = i,col = j;
            for(int k=0;k<sz;k++){
                C[i][j] += (A[row][k]*B[k][col]);
            }
        }
    }
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            A[i][j] = C[i][j];
        }
    }
}

int main()
{
    int A[sz][sz], C[sz][sz];
    mem(C,0);
    read_matrix(A);
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            C[i][j] = A[i][j];
        }
    }
    for(int i=1;i<2;i++){
        result_mat(A,C);
    }
    for(int i=0;i<sz;i++){
        for(int j=0;j<sz;j++){
            printf("%d ",A[i][j]);
        }
        printf("\n");
    }
    return 0;
}
