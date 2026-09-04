#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int case_num) {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    int m;
    cin >> m;
    vector<tuple<int, int, long long>> edges;  
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        int d = a[y] - a[x];
        long long cost = 1LL * d * d * d; 
        edges.push_back({x, y, cost});
    }

    
    vector<long long> dist(n + 1, LLONG_MAX);  
    dist[1] = 0; 
for (int i = 1; i < n; i++) {
   
    for (auto edge : edges) {
        int u = get<0>(edge);  
        int v = get<1>(edge); 
        long long weight = get<2>(edge); 
        if (dist[u] != LLONG_MAX) {
            
            if (dist[u] + weight < dist[v]) {
                
                dist[v] = dist[u] + weight;
            }
        }
    }
}

    cout << "Case " << case_num << ":\n";

    int q;
    cin >> q;
    while (q--) {
        int x;
        cin >> x;

        if (dist[x] == LLONG_MAX || dist[x] < 3) 
            cout << "?\n";
        else
            cout << dist[x] << "\n";
    }
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif

    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        solve(i); // Process each test case
    }
    return 0;
}
