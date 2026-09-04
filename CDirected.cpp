#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> graph;
vector<int> vis;
vector<int> pathvis;
vector<int> parnt;
int p, q;
bool dfs(int node, int par)
{
    vis[node] = 1;
    pathvis[node] = 1;
    parnt[node] = par;
    for (int child : graph[node])
    {
        if (vis[child] == 0)
        {
            if (dfs(child, node) == true)
            {
                return true;
            }
        }
        else if (pathvis[child])
        {
            p = child;
            q = node;
            return true;
        }
    }
    pathvis[node] = 0;
    return false;
}
int main()
{
    int n, m;
    cin >> n >> m;
    graph.resize(n + 1);
    vis.resize(n + 1, 0);
    pathvis.resize(n + 1, 0);
    parnt.resize(n+1,-1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        
    }
    bool b = false;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            b = dfs(i, -1);
            if (b == true)
            {
                break;
            }
        }
    }
    if (b == true)
    {
        cout << "yes" << endl;
        vector<int> path;
        while (q != parnt[p])
        {
            path.push_back(q);
            q = parnt[q];
        }
        reverse(path.begin(), path.end());
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << path[0] << endl;
    }
    else {
        cout<<"IMPOSSIBLE"<<endl;
    }
}