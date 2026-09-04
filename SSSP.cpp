#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001];
int dist[100001];
void dfs(int node,int d){
    visited[node]=1;
    dist[node]=d;
    for(auto child:graph[node]){
        if(visited[child]==0){
            dfs(child,dist[node]+1);
        }
        else{
            if(dist[child]>dist[node]+1){
                dist[child]=dist[node]+1;
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
    dfs(1,0);
    // int ans=0;
    // int min_dist=INT_MAX;
    // for(int i=2;i<=n;i++)
    //  {
    //    if(dist[i]<min_dist){
    //      min_dist=dist[i];
    //      ans=i;
    //    }
    //     else if(dist[i]==min_dist && i<ans){
    //      ans=i;
    //    }
    // }
 
    // cout<<ans<<endl;

    for(int i=1;i<=n;i++){
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    
}