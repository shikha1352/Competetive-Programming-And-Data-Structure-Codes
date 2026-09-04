#include<bits/stdc++.h>
using namespace std;
const int MAX=1e9+7;
vector<vector<int>>graph;
int visited[MAX]={0};
stack<int>st;
void dfs(int node){
    visited[node]=1;
    st.push(node);
    while(!st.empty()){
        int current=st.top();
        cout<<current<<endl;
        st.pop();
        for(int child:graph[current]){
            if(visited[child]==0){
                visited[child]=1;
                st.push(child);
            }
        }
        
    }

}
int main(){
    int m,n;
    cin>>m>>n;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(1);

    
}