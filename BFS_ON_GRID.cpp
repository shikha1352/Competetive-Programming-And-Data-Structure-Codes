#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[50][50];
int dis[50][50];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
bool isValid(int x, int y) {
    if(x < 1 || x > n || y < 1 || y > m)
        return false;
    if(vis[x][y] == 1)
        return false;
    return true;
}

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x, y});
    vis[x][y] = 1;
    dis[x][y] = 0;
    while (!q.empty()) {
        int curx = q.front().first;
        int cury = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int newx = curx + dx[i];
            int newy = cury + dy[i];
            if (isValid(newx, newy)) {
                dis[newx][newy] = dis[curx][cury] + 1;
                vis[newx][newy] = 1;
                q.push({newx, newy});
            }
        }
    }
}

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
        vis[i][j]=0;
        dis[i][j]=INT_MAX;
        }
    }
    bfs(1,1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}