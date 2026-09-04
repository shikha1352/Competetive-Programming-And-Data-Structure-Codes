#include <bits/stdc++.h>
using namespace std;

bool bfs(int node, vector<vector<int>>& graph, vector<int>& vis) {
    queue<pair<int, int>> q;
    q.push({node, -1});  // Start BFS with the node and its parent (-1)
    vis[node] = 1;

    while (!q.empty()) {
        int v = q.front().first;
        int parnt = q.front().second;
        q.pop();

        for (auto it : graph[v]) {
            if (!vis[it]) {
                vis[it] = 1;
                q.push({it, v});
            } 
            // Check for a back edge (cycle detection)
            else if (it != parnt) {
                return true;  // Cycle found
            }
        }
    }
    return false;  // No cycle in this component
}

int32_t main() {
   
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<int> vis(n, 0);

    // Cycle detection in all components
    for (int i = 0; i < n; i++) {
        if (!vis[i]) {
            if (bfs(i, graph, vis)) {
                cout << "YES" << endl;  // Cycle detected
                 // Exit program as we found a cycle
            }
        }
    }

    cout << "NO" << endl;  // No cycle detected in any component
   
}
