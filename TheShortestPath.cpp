#include <bits/stdc++.h>
using namespace std;

#define MAX 10005
#define pii pair<int, int>
vector<pii> city[MAX];
map<string, int> cityMap;
int dist[MAX];

void dijkstra(int src) {
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push(pii(0, src));
    dist[src] = 0;

    while (!pq.empty()) {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &edge : city[u]) {
            int v = edge.second;
            int cost = edge.first;
            if (dist[u] + cost < dist[v]) {
                dist[v] = dist[u] + cost;
                pq.push(pii(dist[v], v));
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n, p, nr, cost, r;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            string str;
            cin >> str >> p;
            cityMap[str] = i;
            for (int j = 0; j < p; j++) {
                cin >> nr >> cost;
                city[i].push_back(pii(cost, nr));
            }
        }

        cin >> r;
        while (r--) {
            string s1, s2;
            cin >> s1 >> s2;
            int u = cityMap[s1];
            int v = cityMap[s2];
            fill(dist, dist + n + 1, INT_MAX);
            dijkstra(u);
            cout << dist[v] << endl;
        }

        for (int i = 0; i <= n; i++)
            city[i].clear();
        cityMap.clear();
    }
    return 0;
}
