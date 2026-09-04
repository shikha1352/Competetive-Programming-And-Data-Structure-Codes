#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> edge;
    for(int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;
        edge.push_back({u, v, weight});
    }
    vector<int> p(n, -1);
    int dist[n + 1];
    for(int i = 1; i <= n; i++)
        dist[i] = INT_MAX; 
    dist[1] = 0;
    for(int j = 1; j <= n - 1; j++) {
       
        for(int i = 0; i < m; i++) { 
            int u = edge[i][0];
            int v = edge[i][1];
            int d = edge[i][2];

            if(dist[u] != INT_MAX && dist[u] + d < dist[v]) {
                dist[v] = dist[u] + d;
            }
        }
    }
    cout<<dist[n]/2<<endl;
}