#include <bits/stdc++.h>
using namespace std;

#define MAX 50
int dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int bfs(int start_x, int start_y, vector<vector<char>>& grid, int h, int w) {
    queue<pair<int, int>> q;
    vector<vector<int>> dist(h, vector<int>(w, 0));
    
    q.push({start_x, start_y});
    dist[start_x][start_y] = 1;
    
    int max_dist = 1;
    
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        
        for (int dir = 0; dir < 8; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            if (nx >= 0 && nx < h && ny >= 0 && ny < w) {
                if (grid[nx][ny] == grid[x][y] + 1 && dist[nx][ny] == 0) {
                    dist[nx][ny] = dist[x][y] + 1;
                    max_dist = max(max_dist, dist[nx][ny]);
                    q.push({nx, ny});
                }
            }
        }
    }
    
    return max_dist;
}

void solve() {
    int h, w, case_num = 1;
    while (cin >> h >> w && (h != 0 || w != 0)) {
        vector<vector<char>> grid(h, vector<char>(w));
        
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> grid[i][j];
            }
        }
        
        int result = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == 'A') {
                    result = max(result, bfs(i, j, grid, h, w));
                }
            }
        }
        
        cout << "Case " << case_num++ << ": " << result << endl;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    solve();
    
    return 0;
}
