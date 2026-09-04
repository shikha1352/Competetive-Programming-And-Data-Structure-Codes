#include <bits/stdc++.h>
using namespace std;
void checkSurrounding(
    int x, int y,
    int n, int m,
    vector<vector<int>>& visited,
    vector<string>& grid,
    queue<pair<int, int>>& q) {
    if (x < 0 || x >= n || y < 0 || y >= m) {
        return; 
    }
    if (visited[x][y] || grid[x][y] != '?') {
        return; 
    }
    if (x - 1 >= 0 && !visited[x - 1][y]) return; // Top neighbor
    if (y - 1 >= 0 && !visited[x][y - 1]) return; // Left neighbor
    if (x + 1 < n && !visited[x + 1][y]) return;  // Bottom neighbor
    if (y + 1 < m && !visited[x][y + 1]) return;  // Right neighbor

   
    visited[x][y] = 1;
   // q.push({x, y});
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    if (n == 1 && m == 1) {
        cout << "0\n";
        return;
    }

    queue<pair<int, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ((i == 0 && grid[i][j] == 'U') || (i == n - 1 && grid[i][j] == 'D') ||
                (j == 0 && grid[i][j] == 'L') || (j == m - 1 && grid[i][j] == 'R')) {
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    while (!q.empty()) {
        //auto [i, j] = q.front();
        int i=q.front().first;
        int j=q.front().second;
        q.pop();

        // Check neighbors and process them
        if (i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 'D') {
            visited[i - 1][j] = 1;
            q.push({i - 1, j});
        }
        if (j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 'R') {
            visited[i][j - 1] = 1;
            q.push({i, j - 1});
        }
        if (i + 1 < n && !visited[i + 1][j] && grid[i + 1][j] == 'U') {
            visited[i + 1][j] = 1;
            q.push({i + 1, j});
        }
        if (j + 1 < m && !visited[i][j + 1] && grid[i][j + 1] == 'L') {
            visited[i][j + 1] = 1;
            q.push({i, j + 1});
        }

        checkSurrounding(i - 1, j, n, m, visited, grid, q); // Top
        checkSurrounding(i + 1, j, n, m, visited, grid, q); // Bottom
        checkSurrounding(i, j - 1, n, m, visited, grid, q); // Left
        checkSurrounding(i, j + 1, n, m, visited, grid, q); // Right
    }


    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j] == 0) {
                ans++;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
