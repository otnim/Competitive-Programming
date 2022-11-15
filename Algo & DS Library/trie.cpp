#include <bits/stdc++.h>
using namespace std;
#define     LIM 50505

int nnode, trie[LIM][30];
int flag[LIM];

void add(string word){
    int id = 0, cur = 0;
    for (char c : word)
    {
        id = c-'a';
        if (trie[cur][id] == -1){
            trie[cur][id] = ++nnode;
        }
        cur = trie[cur][id];
    }
    flag[cur]++;
}

int query(string word){
    int id = 0, cur = 0;
    for (int i = 0; word[i]; i++){
        id = word[i]-'a';
        if (trie[cur][id] != -1){
            cur = trie[cur][id];
        }
        else return -1; /// doesn't exist such word
    }
    return flag[cur];
}

int main(){
    int T; cin>>T;
    while (T--){
        int n, q; cin>>n>>q;
        memset(trie, -1, sizeof trie);
        memset(flag, 0, sizeof flag);
        string s;
        while(n--){
            cin>>s;
            add(s);
        }
        while (q--){
            cin>>s;
            int r = query(s);
            if (r == -1) cout<<"The word '"<<s<<"' doesn't exist."<<endl;
            else if (r == 0) cout<<"The word '"<<s<<"' contain in another word."<<endl;
            else cout<<"The word '"<<s<<"' appears "<<r<<" times."<<endl;
        }
    }
}
