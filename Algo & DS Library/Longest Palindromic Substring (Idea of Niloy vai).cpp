#include <bits/stdc++.h>
using namespace std;
#define LIM  200000


int p[LIM+5];
char str[LIM+5];

void findMaxPalindrome(){
    int c = 0, rht = 0, sz = strlen(str), mx = 1;
    for(int i = 1; i < sz-1; i++){
        int mirr = 2*c - i;
        if(i < rht) p[i] = min(rht-i, p[mirr]);
        while(str[i + 1+p[i]] == str[i - (1+p[i])]) p[i]++;
        if(i+p[i] > rht){
            c = i;
            rht = i + p[i];
        }
    }
    for(int i = 0; i < sz; i++) mx = max(mx, p[i]);
    printf("%d\n", mx);
}

int main(){
    int n; scanf("%d", &n);
    char s[n];
    scanf(" %[^\n]", s); /// s => input string
    int sz = strlen(s);  /// str => modified string
    str[0] = '@';
    str[1] = '#';
    int j = 2;
    for(int i = 0; i < sz; i++){
        str[j++] = s[i];
        str[j++] = '#';
    }
    str[j++] = '$';
    str[j++] = '\0';
    findMaxPalindrome();
}

