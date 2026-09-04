#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001];
void bfs(int node){
    visited[node]=1;
    queue<int>qe;
    qe.push(node);
    while(!qe.empty()){
        int current=qe.front();
        cout<<current<<" ";
        qe.pop();
        for(int child:graph[current]){
            if(visited[child]==0){
            visited[child]=1;
            qe.push(child);
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