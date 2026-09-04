#include<bits/stdc++.h>
using namespace std;
vector<int>graph[10001];
int visited[100001]={0};
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
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);

    }
    int cc_count=0;
    for(int i=0;i<n;i++){
        if(visited[i]==0){
            dfs(i);
            cc_count++;
        }
    }
    cout<<cc_count<<endl;

}