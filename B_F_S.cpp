#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>vis;
void bfs(int node){
    vis[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int cur=q.front();
        cout<<cur<<" ";
        q.pop();
        for(int child:graph[cur]){
            if(vis[child]==0){
                q.push(child);
                vis[child]=1;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n+1,0);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    bfs(1);
}