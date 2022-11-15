#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define pii pair<int, int>


int main(){
    set<string> sat;

    string str;
    getline(cin, str);

    stringstream ss(str);
    string word;
    while(ss>>word){
        sat.insert(word);
    }


    for(auto it : sat) cout<<it<<'\n';
}


