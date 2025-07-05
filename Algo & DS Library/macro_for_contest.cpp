#include <bits/stdc++.h>
using namespace std;

#define BASE1           129
#define BASE2           137
#define MOD1            (1'479'386'893)
#define MOD2            (1'928'476'349)
#define LIM             (2'000'000 + 5)

#define POS_INF         UINT64_MAX
#define NEG_INF         INT64_MIN
#define ff              first
#define ss              second
#define pii             pair<int, int>

#define FAST_IO() do {\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);\
    cout.tie(nullptr);\
} while (0)

/************************print or debug value start************************/
#ifdef LOCAL
    #define dbg(...) do { \
        cerr << "[" << #__VA_ARGS__ << "] = "; \
        print_variadic(cerr, ", ", __VA_ARGS__); \
    } while (0)
#else
    #define dbg(...)
#endif

#define print(...) print_variadic(cout, " ", __VA_ARGS__)

template<typename T, typename... Ts>
void print_variadic(ostream& os, const char* sep, const T& t, const Ts&... ts) {
    os << t;
    ((os << sep << ts), ...);
    os << '\n';
}
/************************print or debug value end************************/

template <typename T> inline void update_min(T &a, T b) { if (b < a) a = b; }
template <typename T> inline void update_max(T &a, T b) { if (b > a) a = b; }
/************************************************************************/


void solve() {
    int32_t m, n, k, q, node, edge;


}

int32_t main() {
    FAST_IO();

    int32_t test_cases = 1;
    //cin >> test_cases;
    while (test_cases--) {
        solve();
    }

    return 0;
}
