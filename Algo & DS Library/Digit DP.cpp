/**Problem: Given two integers L and R. Your task is to find the count of
integers Z in [L, R] such that digit t occurs exactly k times in Z.
*/

#include<bits/stdc++.h>
using namespace std;
#define fread  ios_base::sync_with_stdio(false); cin.tie(NULL);
#define nl    '\n'
#define int    long long
#define pii   pair<int, int>
#define ff    first
#define ss    second
#define LIM   500000


string str;
int D, matchCnt;
int len, dp[10][10][2][2]; ///pos, count of t digit, is current number less than R, MSD or not
bool vis[10][10][2][2];
vector<int> digits;

void toDigit(int n){
    while(n){
        digits.push_back(n%10);
        n /= 10;
    }
    reverse(digits.begin(), digits.end());
}

int countNumbers(int pos, int cnt, bool isSmall, bool isMSD){
    //cout<<pos<<"   "<<isSmall<<"   "<<str<<nl;
    if(pos == len){
        if(cnt == matchCnt){
            return 1;
        }
        return 0;
    }
    if(vis[pos][cnt][isSmall][isMSD]) return dp[pos][cnt][isSmall][isMSD];
    vis[pos][cnt][isSmall][isMSD] = 1;

    int cntNum = 0;
    if(isSmall){
        if(isMSD) cntNum += countNumbers(pos+1, cnt, 1, 1); // 0 bosailam
        else cntNum += countNumbers(pos+1, cnt + (0 == D), 1, 0);

        for(int i = 1; i <= 9; i++){
            str[pos] = char(i+'0');
            cntNum += countNumbers(pos+1, cnt + (i == D), 1, 0);
        }
    }
    else {
        if(isMSD) cntNum += countNumbers(pos+1, cnt, 0 < digits[pos], 1);
        else cntNum += countNumbers(pos+1, cnt + (0 == D), 0 < digits[pos], 0);
        for(int i = 1; i <= digits[pos]; i++){
            str[pos] = char(i+'0');
            if(i < digits[pos]) cntNum += countNumbers(pos+1, cnt + (i == D), 1, 0);
            else cntNum += countNumbers(pos+1, cnt + (i == D), 0, 0);
        }
    }

    return dp[pos][cnt][isSmall][isMSD] = cntNum;
}

int32_t main(){
    //freopen("ip.txt", "r", stdin);
    //freopen("out.txt", "w", stdin);

    int T = 1; //cin>>T;
    for(int tc = 1; tc <= T; tc++){
        int L, R; cin>>L>>R>>D>>matchCnt;
        int zero = 0;
        if(L == 0 && D == 0 && matchCnt == 1) zero++;
        str = to_string(R);
        toDigit(R);
        len = digits.size();
        int hi = countNumbers(0, 0, 0, 1) + zero;
        //cout<<"**********************************\n";
        digits.clear();
        str = to_string(L-1);
        toDigit(L-1);
        len = digits.size();
        memset(vis, 0, sizeof vis);
        int lo = countNumbers(0, 0, 0, 1);

        cout<<hi<<"  "<<lo<<"  "<<hi-lo<<nl;
    }
}

