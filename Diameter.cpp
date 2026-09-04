#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>vis;
int maxD;
int maxNode;
void dfs(int node,int dis){
    vis[node]=1;
   if(dis>maxD){
    maxD=dis;
    maxNode=node;
   }
    for(int child:graph[node]){
        if(vis[child]==0){
            dfs(child,dis+1);
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n+1,0);
    while(m--)
    {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    maxD=-1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i,0);
        }
    }
    for(int i=1;i<=n;i++){
        vis[i]=0;
    }
    maxD=-1;
    dfs(maxNode,0);
    cout<<maxD<<endl;
}