#include<bits/stdc++.h>
using namespace std;
#define LL  long long
#define LIM 100000



int main(){
    int n; cin>>n;
    int a, b, c, t = 3;
    int idx = 3, a_b, a_c, b_c;
    int ara[n] = {0};
    for(int i = 0; i < 3; i++){
        if(i == 0) cout<<"? 1 2"<<'\n';
        if(i == 1) cout<<"? 2 3"<<'\n';
        if(i == 2) cout<<"? 3 1"<<'\n';
        fflush(stdout);

        int response; cin>>response;
        ara[i] = response;
    }
    a = (ara[0] + ara[2] - ara[1])/ 2;
    b = ara[0] - a;
    c = ara[2] - a;
    //cout<<a<<"  "<<b<<"  "<<c<<'\n';
    ara[0] = a, ara[1] = b, ara[2] = c;
    //cout<<ara[0]<<"  "<<ara[1]<<"  "<<ara[2]<<'\n';
    for(int i = 3; i < n; i++){
        cout<<"? "<<i<<' '<<(i+1)<<'\n';
        fflush(stdout);
        int response; cin>>response;
        ara[i] = response - ara[i-1];
    }
    cout<<"!";
    for(int i = 0; i < n; i++) cout<<' '<<ara[i];
    cout<<'\n';

    fflush(stdout);
}



