#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9; // Define a very large value for infinity

void solve() {
    int n;
    cin >> n; // Number of processors
    
    vector<vector<int>> adj(n, vector<int>(n, INF)); // Initialize adjacency matrix
    
    // Input the lower triangular part of the adjacency matrix
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            string cost;
            cin >> cost;
            if (cost == "x") {
                adj[i][j] = adj[j][i] = INF; // No direct connection
            } else {
                adj[i][j] = adj[j][i] = stoi(cost); // Convert string to integer
            }
        }
    }

    // Dijkstra's Algorithm to find the shortest path from node 0 (processor 1)
    vector<int> dist(n, INF);
    vector<bool> visited(n, false);
    dist[0] = 0; // Distance to itself is 0

    for (int i = 0; i < n; i++) {
        // Find the unvisited node with the smallest distance
        int u = -1;
        for (int j = 0; j < n; j++) {
            if (!visited[j] && (u == -1 || dist[j] < dist[u])) {
                u = j;
            }
        }
        
        if (dist[u] == INF) break; // If the smallest distance is infinity, stop
        
        visited[u] = true;

        // Update distances for neighbors of u
        for (int v = 0; v < n; v++) {
            if (adj[u][v] != INF && !visited[v]) {
                dist[v] = min(dist[v], dist[u] + adj[u][v]);
            }
        }
    }

    // Find the maximum time among the shortest distances to all processors
    int result = 0;
    for (int i = 0; i < n; i++) {
        // if (dist[i] == INF) { // If a processor is unreachable
        //     cout << "Impossible to broadcast to all processors." << endl;
        //     return;
        // }
        result = max(result, dist[i]);
    }

    cout << result << endl; // Minimum broadcast time
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    solve();
    return 0;
}
