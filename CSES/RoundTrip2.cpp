#include <bits/stdc++.h>
using namespace std;
vector<int>graph[200002];
vector<bool> vis;
vector<bool> stckvis;
stack<int> recursionStack;
bool dfs(int node) {
    vis[node] = true;
    stckvis[node] = true;
    recursionStack.push(node);

    for (auto child : graph[node]) {
        if (!vis[child]) {
            if (dfs(child))
                return true;
        }
        if (stckvis[child]) {
            recursionStack.push(child);
            return true;
        }
    }
    recursionStack.pop();
    stckvis[node] = false;
    return false;
}
int main() {
    int n, m;
    cin >> n >> m;
    vis.resize(n + 1, false);
    stckvis.resize(n + 1, false);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && dfs(i)) {
            break;
        }
    }
    if(recursionStack.empty())
	{		
		cout << "IMPOSSIBLE" << endl;
		return 0;
	}
    vector<int> res;
    int temp = recursionStack.top();
    while (!recursionStack.empty()) {
        res.push_back(recursionStack.top());
        recursionStack.pop();
        if (res.back() == temp && res.size() > 1) {
            break;
        }
    }

   reverse(res.begin(),res.end());
    cout << res.size() << endl;
    for (auto u : res) {
        cout << u << " ";
    }

    return 0;
}
