#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
const ll mod = 1e18;
const int mx = 100001;

void solve() {
    int n;
    cin >> n;

    // Build the graph
    vector<vector<int>> graph(n);
    for (int i = 0; i < n; i++) {
        int x, l;
        cin >> x >> l;
        vector<int> a(l);
        for (int j = 0; j < l; j++) {
            cin >> a[j];
            graph[x].push_back(a[j]);
            graph[a[j]].push_back(x);
        }
    }

    // Input c1 and c2
    int c1, c2;
    cin >> c1 >> c2;

    // BFS to find the shortest path
    vector<int> d(n, -1);
    queue<int> q;
    q.push(c1);
    d[c1] = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (auto it : graph[node]) {
            if (d[it] == -1) { // Not visited
                d[it] = d[node] + 1;
                q.push(it);

                // Stop early if we reach c2
                if (it == c2) {
                    break;
                }
            }
        }
    }

    // Output the result
    cout << c1 << " " << c2 << " " << d[c2]-1 << endl;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    
    int t;
    cin >> t;

    // Solve each test case
    for (int i = 0; i < t; i++) {
        if (i > 0) {
            // Print a blank line between test case outputs
            cout << endl;
        }
        solve();
    }

    return 0;
}
