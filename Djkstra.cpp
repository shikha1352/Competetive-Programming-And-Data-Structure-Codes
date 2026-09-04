#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 7;
int n, m;
vector<pair<int, int>> graph[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<int> dist;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; ++i) {
            graph[i].clear();
        }
        while (!pq.empty()) {
            pq.pop();
        }
        dist.assign(n + 1, INF);
        for (int i = 0; i < m; i++)
        {
            int a, b, w;
            cin >> a >> b >> w;
            graph[a].push_back({b, w});
        }
        int x, y;
        cin >> x >> y;
        pq.push({0, x});
        dist[x] = 0;
        while (!pq.empty())
        {
            int current = pq.top().second;
            int curr_d = pq.top().first;
            pq.pop();
            for (pair<int, int> edge : graph[current])
            {
                if (curr_d + edge.second < dist[edge.first])
                {
                    dist[edge.first] = curr_d + edge.second;
                    pq.push({dist[edge.first], edge.first});
                }
            }
        }
        if (dist[y] < INF)
            cout << dist[y] << endl;
        else
            cout << "NO" << endl;
    }
}
