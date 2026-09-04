#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1,0,+1,0};
int dy[] = {0,+1,0,-1};

void solve() {
    int n, m, j;
    cin >> n >> m >> j;
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    queue<pair<pair<int,int>,int>> q;
    vector<vector<int>> visited(n, vector<int>(m, -1)); // Simplified 2D array
    
    int startX = -1, startY = -1;
    int endX = -1, endY = -1;

    for (int i = 0; i < n; i++) {
        for (int k = 0; k < m; k++) {
            if (grid[i][k] == '@') {
                startX = i;
                startY = k;
            }
            if (grid[i][k] == 'x') {
                endX = i;
                endY = k;
            }
        }
    }

    q.push({{startX, startY}, 0});
    visited[startX][startY] = 0;

    while (!q.empty()) {
        int x=q.front().first.first;
        int y=q.front().first.second;
        int trapsUsed=q.front().second;
        q.pop();
        if (x == endX && y == endY && trapsUsed*2<= j) {
            cout << "SUCCESS" << endl;
            return;
        }
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;

            if (grid[nx][ny] == '#') continue;

            int newTrapsUsed = trapsUsed + (grid[nx][ny] == 's' ? 1 : 0);

            if (newTrapsUsed > j || (visited[nx][ny] != -1 && visited[nx][ny] <= newTrapsUsed)) continue;

            visited[nx][ny] = newTrapsUsed;

            q.push({{nx, ny}, newTrapsUsed});
        }
    }

    cout << "IMPOSSIBLE" << endl;
}

int main() {
   
    solve();
    return 0;
}
