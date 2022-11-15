/// LOJ - Number Transformation

#include <bits/stdc++.h>
using namespace std;
#define sz 1005

int vis[sz], lev[sz];
vector<int> primes;

int bfs(int node, int t){
    memset(vis, 0, sizeof(vis));
    memset(lev, 0, sizeof(lev));
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(node);
    vis[node] = 1;
    while (!q.empty()){
        int u = q.front(); q.pop();
        if (u > t) continue;
        for (int i = 0; i < primes.size(); i++){
            if (u < primes[i]) break;
            if (u%primes[i] == 0 && u != primes[i]){
                int v = u + primes[i];
                if (!vis[v]){
                    lev[v] = lev[u] + 1;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
        if (lev[t]) return lev[t];
    }
    return -1;
}

int main()
{
    int T, s, t, i, j, p; scanf("%d", &T);
    for (p = 2; p <= sz; p++){
        bool isPrime = true;
        for (i = 2; i < p; i++)
            if (p%i == 0) isPrime = false;
        if (isPrime) primes.push_back(p);
    }

    for (i = 0; i < T; i++){
        scanf("%d %d", &s, &t);
        int res = bfs(s, t);
        if (s == t) printf("Case %d: 0\n", i+1);
        else if (s == 1 || t < s) printf("Case %d: -1\n", i+1);
        else printf("Case %d: %d\n", i+1, res);
    }
}


