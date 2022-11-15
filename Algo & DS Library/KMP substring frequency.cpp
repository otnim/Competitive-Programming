#include <bits/stdc++.h>
using namespace std;
#define     pb  push_back

vector<int> lps;
int tc;
void createLPS(string pat)
{
    lps.pb(0);
    int i = 0, j = 1;
    for ( ; pat[j]; ){
        if (pat[i] == pat[j]){
            lps.pb(i+1);
            ++i, ++j;
        }
        else{
            if (i != 0) i = lps[i-1];
            else {
                ++j;
                lps.pb(0);
            }
        }
    }
    //for (int i : lps) cout<<i<<" ";
    //cout<<"\n\n";
}

void KMP(string text, string pat)
{
    int i = 0, j = 0, cnt = 0;
    ++tc;
    if (pat.size() == 1){
        for(char c : text){
            if (c == pat[0]) ++cnt;
        }
        cout<<"Case "<<tc<<": "<<cnt<<"\n";
        return;
    }
    for (; text[i]; ){
        if (j == pat.size()-1 && (pat[j] == text[i])){
            ++cnt;
            j = lps[j-1];

        }
        if (text[i] == pat[j]) {
            ++i, ++j;
        }
        else{
            if (j != 0) j = lps[j-1];
            else ++i;
        }
    }
    cout<<"Case "<<tc<<": "<<cnt<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int i, j, sz, T; cin>>T;
    string text, pat;
    for (int t = 1; t <= T; t++){
        cin>>text>>pat;

        createLPS(pat);
        KMP(text, pat);

        lps.clear();
    }
}
