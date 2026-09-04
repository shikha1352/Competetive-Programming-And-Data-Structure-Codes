#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001];
void bfs(int node){
    visited[node]=1;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int current=q.front();
        cout<<current<<" ";
        q.pop();
    for(int child:graph[current]){
        if(visited[child]==0){
            visited[child]=1;
            q.push(child);
        }
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
    bfs(0);
}