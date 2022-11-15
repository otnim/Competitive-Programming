#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> indexed_set;


int main(){
    indexed_set is;

    for(int i = 1; i <= 5; i++) is.insert(i+3);
    is.insert(1);
    is.erase(is.find_by_order(1));

    //for(int i = 0; i <= 5; i++)
    int res = *(is.find_by_order(0));
    if(res == 0) cout<<"y\n";
    cout<<"res = "<<res<<'\n';
    cout<<'\n';
    //for(int i = 0; i <= 5; i++) cout<<(is.order_of_key(23))<<' ';

}
