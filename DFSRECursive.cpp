#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph; // Adjacency list
vector<int> vis; // Visited array
void dfs(int node) {
    vis[node] = 1;
    cout<<node<<" ";
    for(auto child:graph[node]){
        if(!vis[child]){
            dfs(child);
        }
    }
    
}

int32_t main() {
    int n, m;
    cin >> n >> m;
    graph.resize(n+1);
    vis.resize(n+1, 0);

    while (m--) {
        int a,b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1); 
    return 0;
}
