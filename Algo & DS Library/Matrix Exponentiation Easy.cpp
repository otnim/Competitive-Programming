#include <bits/stdc++.h>
using namespace std;
#define  LL    long long
#define  LIM   5
#define  fread ios_base::sync_with_stdio(false); cin.tie(NULL);

LL MOD;

struct matrix{
    LL v[LIM][LIM];
    LL row, col;
};

matrix multiplyMatrix(matrix A, matrix B){
    matrix M;
    M.row = M.col = A.row; /// row = col

    for(LL r = 0; r < A.row; r++){
        for(LL c = 0; c < B.col; c++){
            LL sum = 0;
            for(LL i = 0; i < A.col; i++){ /// B.row
                sum += A.v[r][i]*B.v[i][c];
                sum %= MOD;
            }
            M.v[r][c] = sum;
        }
    }
    return M;
}

matrix matBigMod(matrix mat, LL pow){
    if(pow == 1) return mat;
    if(pow&1) return multiplyMatrix(mat, matBigMod(mat, pow-1));
    matrix tmp = matBigMod(mat, pow/2);
    return multiplyMatrix(tmp, tmp);
}

int main(){
    LL m, n;
    while(scanf("%lld %lld", &n, &m) != EOF){
        MOD = 1<<m;
        if(n < 2){
            cout<<(n%MOD)<<'\n';
            continue;
        }
        matrix mat;
        mat.row = mat.col = 2;
        for(LL i = 0; i < 2; i++){
            for(LL j = 0; j < 2; j++) mat.v[i][j] = 1;
        }
        mat.v[0][0] = 0;
        mat = matBigMod(mat, n-1);
        cout<<mat.v[1][1]<<'\n';
    }
}
