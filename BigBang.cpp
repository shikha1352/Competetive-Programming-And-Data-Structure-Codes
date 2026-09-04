#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;

const int MAXN = 1005;
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define memo(a, b) memset((a), (b), sizeof(a))

int n, m, dist[MAXN];
vector<pii> adj[MAXN];
bool visited[MAXN];

void dfs(int u) {
    visited[u] = 1;
    for (auto [v, _] : adj[u]) {
        if (!visited[v]) dfs(v);
    }
}

void BellmanFord() {
    memo(visited, 0);
    fill(dist, dist + n, INF);
    dist[0] = 0;
    
    for (int i = 0; i < n - 1; i++) {
        for (int u = 0; u < n; u++) {
            for (auto [v, wt] : adj[u]) {
                if (dist[v] > dist[u] + wt) {
                    dist[v] = dist[u] + wt;
                }
            }
        }
    }

    bool cycle = false;
    for (int u = 0; u < n; u++) {
        for (auto [v, wt] : adj[u]) {
            if (dist[v] > dist[u] + wt) {
                if (!visited[v]) dfs(v);
                cycle = true;
            }
        }
    }

    if (cycle) {
        for (int i = 0; i < n; i++) {
            if (visited[i])
                cout << ' ' << i;
        }
        cout << "\n";
    } else {
        cout << " impossible\n";
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    for (int cs = 1; cs <= t; cs++) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            adj[i].clear();
        }
        int u, v, c;
        for (int i = 0; i < m; i++) {
            cin >> u >> v >> c;
            adj[v].pb(mp(u, c));
        }

        cout << "Case " << cs << ":";
        BellmanFord();
    }

    return 0;
}
