#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
int visited[10001]={0};
int dist[10001]={0};
void dfs(int node,int dst){
    visited[node]=1;
    dist[node]=dst;
    for(int child:graph[node]){
        if(visited[child]==0){
            dfs(child,dist[node]+1);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1,0);
    for(int i=1;i<n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
}