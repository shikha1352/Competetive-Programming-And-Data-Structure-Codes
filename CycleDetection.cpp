#include<bits/stdc++.h>
using namespace std;
vector<int>graph[100001];
int visited[100001];
bool dfs(int node,int parnt){
    visited[node]=1;
    for(int child:graph[node]){
        if(visited[child]==0){
            if(dfs(child,node)==true){
                return true;
            }
            
        }
        else {
        if(child!=parnt){
                
                return true;
            }
        }
    }
    return false;
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
    bool b;
    for(int i=1;i<=n;i++){
        if(visited[i]==0){
            if(dfs(i,-1)==true){
                b=true;
                break;
            }
        }
    }

    cout<<b<<endl;
}