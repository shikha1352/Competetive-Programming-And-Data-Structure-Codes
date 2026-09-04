#include <bits/stdc++.h>
using namespace std;
struct edge {
    int a, b;
    long long w;
};
vector<int> par, sz;
int find(int a) {
    if (par[a] == -1) {
        return a;
    }
    return (par[a] = find(par[a]));
}
bool merge(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) return false;
    if (sz[a] < sz[b]) swap(a, b);
    par[b] = a;
    sz[a] += sz[b];
    return true;
}
bool mst(vector<edge>& edges, int n, long long orLimit) {
    par.assign(n + 1, -1);
    sz.assign(n + 1, 1);
    int count = 0;
    for (auto& e : edges) {
        if ((e.w & orLimit) == e.w) {
            if (merge(e.a, e.b)) {
                count++;
                if (count == n - 1) return true;
            }
        }
    }
    return count == n - 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<edge> edges(m);
        for (int i = 0; i < m; i++) {
            cin >> edges[i].a >> edges[i].b >> edges[i].w;
        }
        long long low = 0, high = (1LL << 30) - 1, min_sum = LLONG_MAX;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (mst(edges, n, mid)) {
                min_sum = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        cout << min_sum << endl;
    }
    return 0;
}
