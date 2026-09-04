#include<bits/stdc++.h>
using namespace std;
vector<int>graph[200002];
int vis[200002];
int parnt[200002];
int n,m;
vector<int>path;
bool bfs(int node){
    vis[node]=1;
    parnt[node]=0;
    queue<int>q;
    q.push(node);
    while(!q.empty()){
        int current=q.front();
        if(current==n){
            return true;
        }
        q.pop();
        for(int child:graph[current]){
            if(vis[child]==0){
                q.push(child);
                vis[child]=1;
                parnt[child]=current;
            }
        }
    }
    return false;
}
int main(){
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(bfs(1)){
        int q=n;
        
        while(q!=0){
            path.push_back(q);
            q=parnt[q];
        }
        cout<<path.size()<<endl;
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size()-1;i++){
            cout<<path[i]<<" ";
        }
        cout<<n<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}