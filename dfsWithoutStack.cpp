#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001];
void dfs(int node){
    visited[node]=1;
    cout<<node<<" ";
    for(auto child:graph[node]){
        if(visited[child]==0){
            dfs(child);
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
    dfs(0);
}