#include<bits/stdc++.h>
using namespace std;
vector<int>graph[200002];
int vis[200002];
vector<int>path;
void dfs(int node){
    vis[node]=1;
    for(int child:graph[node]){
        if(vis[child]==0){
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
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
        path.push_back(i);
        dfs(i);
        cnt++;
        }
    }
    int p=path.size();
    cout<<cnt-1<<endl;
    for(int i=0;i<n;i++){
        if(p>=2){
            cout<<path[i]<<" "<<path[i+1]<<endl;
            p--;
        }

    }
}