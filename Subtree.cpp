#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[1000001];
int subtree[100001];
int dfs(int node){
    visited[node]=1;
    int curr_size=1;
    for(int child:graph[node]){
        if(visited[child]==0){
            curr_size += dfs(child);
        }
       
    }
    subtree[node]=curr_size;
        
    return curr_size;
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
    dfs(1);
    for(int i=1;i<=n;i++){
         cout<<subtree[i]<<" ";
     }
}