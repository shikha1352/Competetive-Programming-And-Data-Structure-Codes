#include<bits/stdc++.h>
using namespace std;
vector<int>graph[2000002];
int visited[2000002];
vector<int>rb;
void dfs(int node){
    visited[node]=1;
    for(int child:graph[node]){
        if(visited[child]==0){
            dfs(child);
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
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            dfs(i);
            rb.push_back(i);
        }
    }
    cout<<rb.size()-1<<endl;
    for(int i=1;i<rb.size();i++){
        cout<<rb[i-1]<<" "<<rb[i]<<endl;
    }
}