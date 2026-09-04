#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>vis;
vector<int>col;
bool dfs(int node,int c){
    vis[node]=1;
    col[node]=c;
    for(int child:graph[node]){
        if(vis[child]==0){
            if(dfs(child,c^1)==false){
                return false;
            }
        }
        else 
        {
            if(col[node]==col[child]){
            return false;
        }
        }
    }
    return true;
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n+1,0);
    col.resize(n+1,-1);
    while(m--){

        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool b;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
           b=dfs(i,0);
            if(b==false){
                break;
            }
        }
    }
    if(b==true){
        for(int i=1;i<=n;i++){
            cout<<col[i]+1<<" ";
        }
    }
    else{
        cout<<"IMPOSSIOBLE"<<endl;
    }
}