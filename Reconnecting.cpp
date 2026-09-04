#include <bits/stdc++.h>
using namespace std;

struct edge {
    int a, b, w;
};

bool comp(edge a, edge b) {
    return a.w < b.w;
}

int find(int a, vector<int> &par) {
    if (par[a] == -1)
        return a;
    return par[a] = find(par[a], par); // Path compression
}

void merge(int a, int b, vector<int> &par) {
    par[a] = b;
}

int kruskal(int n, vector<edge> &edges) {
    vector<int> par(n + 1, -1);
    sort(edges.begin(), edges.end(), comp);
    int mst_cost = 0, edges_used = 0;

    for (const auto &e : edges) {
        int x = find(e.a, par);
        int y = find(e.b, par);
        if (x != y) {
            mst_cost += e.w;
            merge(x, y, par);
            edges_used++;
            if (edges_used == n - 1) break; // Stop if MST is complete
        }
    }

    return mst_cost;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);

    bool first_case = true;
    int n;

    while (cin >> n) {
        if (!first_case) cout << '\n';
        first_case = false;

        vector<edge> original_edges, all_edges;
        int original_cost = 0;

        // Read the original MST edges
        for (int i = 0; i < n - 1; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            original_edges.push_back({a, b, w});
            original_cost += w;
        }

        // Read the additional K edges
        int k;
        cin >> k;
        vector<edge> new_edges(k);
        for (int i = 0; i < k; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            new_edges[i] = {a, b, w};
        }

        // Read the originally available M edges
        int m;
        cin >> m;
        vector<edge> original_available_edges(m);
        for (int i = 0; i < m; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            original_available_edges[i] = {a, b, w};
        }

        // Combine edges for new MST calculation
        all_edges = original_available_edges;
        all_edges.insert(all_edges.end(), new_edges.begin(), new_edges.end());

        // Calculate new MST cost
        int new_cost = kruskal(n, all_edges);

        // Output results
        cout << original_cost << '\n' << new_cost << '\n';
    }

    return 0;
}
