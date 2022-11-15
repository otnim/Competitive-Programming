///UVa 11988 - Broken Keyboard (a.k.a. Beiju Text)
/// Verdict: AC

#include <bits/stdc++.h>
using namespace std;
#define  nl    '\n'


int main(){
    string str;
    while(cin>>str){
        list<char> lst;
        list<char> :: iterator it;

        it = lst.end();
        for(int i = 0; str[i]; i++){
            if(str[i] == '[') it = lst.begin();
            else if(str[i] == ']') it = lst.end();
            else lst.insert(it, str[i]); /// it point kora position e str[i] set korbe
        }

        for(char ch : lst) cout<<ch;
        cout<<nl;
    }
}



