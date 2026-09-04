#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<vector<int>>graphT;
vector<int>vis;
stack<int>st;
int scc=0;
vector<int>path;
void dfs(int node){
    vis[node]=1;
    for(int child:graph[node]){
        if(vis[child]==0){
            dfs(child);
        }
    }
    st.push(node);
}
void dfs2(int node){
    vis[node]=1;
    for(int child:graphT[node]){
        if(vis[child]==0){
            dfs2(child);
        }
         
    }
    path.push_back(node);
   
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    graphT.resize(n+1);
    vis.resize(n+1,0);
    path.resize(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graphT[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            dfs(i);
        }
    }
   for(int i=1;i<=n;i++){
        vis[i]=0;
   }
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(vis[node]==0){
            path.clear();
            scc++;
            dfs2(node);
            for(int v:path){
                cout<<v<<" ";
            }
            cout<<endl;
        }
    }
    cout<<scc<<endl;
   
}