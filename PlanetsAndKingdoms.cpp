#include<bits/stdc++.h>
using namespace std;
vector<int>graph[2000001];
vector<int>graphT[2000001];
int visited[2000001];
stack<int>st;
vector<int>sc;
int scc=0;
void dfs(int node){
    visited[node]=1;
    for(int child:graph[node]){
        if(!visited[child]){
            dfs(child);
        }
    }
    st.push(node);
}
void dfs3(int node){
    visited[node]=scc;
    for(int child:graphT[node]){
        if(!visited[child]){
            dfs3(child);
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
        graphT[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            dfs(i);
        }
    }
    
    memset(visited,0,sizeof(visited));
    while(!st.empty()){
        int node=st.top();
        st.pop();
        if(!visited[node]){
            scc++;
            dfs3(node);
        }
    }
    cout<<scc<<endl;
    for(int i=1;i<=n;i++){
        cout<<visited[i]<<" ";
    }
    cout<<endl;
}