#include<bits/stdc++.h>
using namespace std;
vector<int>graph[2000002];
int visited[2000002];
int dp[2000002];
int nextnode[2000002];
void dfs(int node){
    visited[node]=1;
    for(int child:graph[node]){
        if(visited[child]==0){
            dfs(child);
        }
        if(dp[child]!=-1 && (dp[child]+1>dp[node])){
            dp[node]=dp[child]+1;
            nextnode[node]=child;
        }
    }

}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        dp[i]=-1;

    }
    dp[n]=1;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
    }
    dfs(1);
    if(dp[1]==-1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dp[1]<<endl;
        int node=1;
        while(node){
            cout<<node<<" ";
            node=nextnode[node];
        }
    }

}