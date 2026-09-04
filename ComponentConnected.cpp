#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001]={0};
vector<vector<int>>cc;
vector<int>current_cc;
void dfs(int node){
    visited[node]=1;
    current_cc.push_back(node);
    for(int child:graph[node]){
        if(visited[child]==0){
            dfs(child);
        }
        
    }
    
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++) {
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int cnt =0;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            current_cc.clear();
            dfs(i);
            cc.push_back(current_cc);
            cnt++;
        }
    }
    cout<<"connected component is:"<<cc.size()<<endl;
    for(auto child:cc){
        for(auto vertex:child){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
    
}