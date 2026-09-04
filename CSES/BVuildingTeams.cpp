#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[200002];
int vis[200002];
int col[200002];
int flag = 0;
bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;
    for (int child : graph[node])
    {
        if (vis[child] == 0)
        {
            if (dfs(child, c ^ 1) == false)
            {
                return false;
            }
        }
        else
        {
            if (col[node] == col[child])
            {
                return false;
            }
        }
    }

    return true;
}
int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool b;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            b = dfs(i, 0);
            if (b == false)
            {
                break;
            }
        }
    }
    if (b == true)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << col[i] + 1 << " ";
        }
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}