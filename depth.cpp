#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001];
void dfs(int node){
    stack<int>st;
    visited[node]=1;
    st.push(node);
    while(!st.empty()){
        int current=st.top();
        cout<<current<<" ";
        st.pop();
        for(int child:graph[current]){
            if(visited[child]==0){
                st.push(child);
                visited[child]=1;
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
    dfs(0);
}