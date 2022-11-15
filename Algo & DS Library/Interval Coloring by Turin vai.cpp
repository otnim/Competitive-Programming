#include <cstdio>
#include <set>
#include <tuple>
#include <utility>
using namespace std;
using ll = long long;
using ii = pair<int,int>;
using tpl = tuple<int,int,int>;

#define mt make_tuple

const int mx = 2e5+5;
void solve(int cs){
    int n, k=1;
    scanf("%d", &n);

    set<tpl> st;
    st.insert(mt(1, n+n, 0));

    for(int i=1,l,r; i<=n; i++, k++){
        scanf("%d %d", &l, &r);
        auto it = st.upper_bound(mt(l,n+n,k)); it--;
        auto jt = st.upper_bound(mt(r,n+n,k));

        tpl lw = *it, hh = *prev(jt);
        st.erase(it, jt);

        if(get<0>(lw) < l) st.insert(mt(get<0>(lw), l-1, get<2>(lw)));
        if(get<1>(hh) > r) st.insert(mt(r+1, get<1>(hh), get<2>(hh)));
        st.insert(mt(l, r, k));
    }

    set<int> ans;
    for(auto it : st)
        if(get<2>(it))
            ans.insert(get<2>(it));
    printf("Case %d: %d\n", cs, ans.size());
}

int main(){
    int tc; scanf("%d", &tc);
    for(int cs=1; cs<=tc; cs++)
        solve(cs);
    return 0;
}

