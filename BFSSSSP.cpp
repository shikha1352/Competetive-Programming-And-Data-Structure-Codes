#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001];
int dist[100001];
void bfs(int node){
    queue<int>q;
    q.push(node);
    visited[node]=1;
    dist[node]=0;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int child:graph[current]){
            if(visited[child]==0){
                visited[child]=1;
                q.push(child);
                dist[child]=dist[current]+1;
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bfs(1);
    cout<<dist[n];
}