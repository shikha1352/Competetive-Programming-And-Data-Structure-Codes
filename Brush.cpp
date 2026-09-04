#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
vector<pair<int,int>>v[1001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
vector<int>dist;
int main() {
    int t,cs=1;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        dist.resize(n + 1);
        while (m--) {
            int a, b, w;
            cin >> a >> b >> w;
            v[a].push_back({b, w});
            v[b].push_back({a, w});
        }

        for (int i = 1; i <= n; i++) {
            dist[i] = INF;
        }
        pq.push({0, 1});
        dist[1] = 0;
        while (!pq.empty()) {
            int current = pq.top().second;
            int current_d = pq.top().first;
            pq.pop();
            for (pair<int,int> edge : v[current]) {
                if (current_d + edge.second < dist[edge.first]) {
                    dist[edge.first] = current_d + edge.second;
                    pq.push({dist[edge.first], edge.first});
                }
            } 
        }
        cout<<"Case "<<cs++<<": ";
        if (dist[n] == INF) {
            cout << "Impossible" << endl;
        } else {
            cout << dist[n] << endl;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> empty_pq;
        swap(pq, empty_pq);
        for (int i = 1; i <= n; i++) {
            v[i].clear();
        }
    }
    return 0;
}
