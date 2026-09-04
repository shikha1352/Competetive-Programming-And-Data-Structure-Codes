#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N = 1e5 + 9;
map<int, vector<int>> adj;
int visited[N];

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    cout.tie(NULL);
}

void bfs(int start) {
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto neighbor : adj[curr]) {
            if (visited[neighbor] != 1) {
                q.push(neighbor);
                visited[neighbor] = 1;
            }
        }
    }
}

int32_t main() {
    fast_io();

    int t = 1;
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        adj.clear();
        char max_node;
        cin >> max_node;
        cin.ignore();
        int nodes = max_node - 'A' + 1;
        string edge;
        while (getline(cin, edge) && edge != "") {
            adj[edge[0] - 'A' + 1].pb(edge[1] - 'A' + 1);
            adj[edge[1] - 'A' + 1].pb(edge[0] - 'A' + 1);
        }
        int components = 0;
        for (int i = 1; i <= nodes; i++) {
            if (!visited[i]) {
                bfs(i);
                components++;
            }
        }
        cout << components << '\n';
        if (t)
            cout << '\n';
    }
    return 0;
}
