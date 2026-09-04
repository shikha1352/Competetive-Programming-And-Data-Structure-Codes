#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, int>>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
        graph[b].push_back({a, w}); 
    }

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, adjNode] = pq.top();
        pq.pop();

        if (d > dist[adjNode]) continue;

        for (auto [node, w] : graph[adjNode]) {
            if (d + w < dist[node]) {
                dist[node] = d + w;
                parent[node] = adjNode;
                pq.push({dist[node], node});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1 << endl;
    } else {
        vector<int> path;
        for (int v = n; v != -1; v = parent[v]) {
            path.push_back(v);
        }
        reverse(path.begin(), path.end());

        for (int node : path) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
