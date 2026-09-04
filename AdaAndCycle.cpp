#include<bits/stdc++.h>
using namespace std;
vector<int> graph[2001];
int ans;
int n;
bool bfs(int s){
    bool vis[n+1];
    int p[n+1];
    memset(vis,0,sizeof(vis));
    memset(p,-1,sizeof(p));
    vis[s]=true;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int v=q.front();
        q.pop();
        for(int u:graph[v]){
            if(!vis[u]){
                vis[u]=true;
                q.push(u);
                p[u]=v;
            }
            else if(u==s){
                vector<int>path;
                for(int i=v;i!=-1;i=p[i]){
                    path.push_back(i);
                }
                ans=path.size();
                return true;
            }
        }
    }
    return false;
}

int main() {
    int x;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> x;
            if(x == 1)
                graph[i].push_back(j);
        }
    }
    for(int i = 1; i <= n; i++) {
        ans=0;
        if(bfs(i)){
            cout<<ans<<endl;
        }
            
        else
            cout << "NO WAY" << endl;
    }
    return 0;
}
