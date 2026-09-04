#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int a, b, cost;
};

int main() {
    vector<Edge> edges;
    const int INF = 1000000000;
    int n, m;
    cin >> n >> m;
    while (m--) {
        int a, b, cost;
        cin >> a >> b >> cost;
        edges.push_back({a, b, cost});
    }
    
    vector<int> d(n, INF); // Initialize distances with INF
    vector<int> p(n, -1);
    int x = -1;

    // Bellman-Ford Algorithm
    for (int i = 0; i < n; ++i) { // Run relaxation process n times
        x = -1;
        for (Edge e : edges) {
            if (d[e.a] < INF) {
                if (d[e.a] + e.cost < d[e.b]) {
                    d[e.b] = d[e.a] + e.cost;
                    p[e.b] = e.a;
                    x = e.b; // Store the last vertex relaxed
                }
            }
        }
    }

    // Check if there's relaxation from the last relaxed vertex
    if (x != -1) {
        int y = x;
        for (int i = 0; i < n; ++i)
            y = p[y];

        vector<int> cycle;
        for (int v = y;; v = p[v]) {
            cycle.push_back(v);
            if (v == y && cycle.size() > 1)
                break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << "Negative cycle: ";
        for (int v : cycle)
            cout << v + 1 << ' '; // Print vertices with +1 offset
        cout << endl;
    } else {
        cout << "No negative cycle found.";
    }

    return 0;
}
