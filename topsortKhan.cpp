#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>in;
vector<int>res;
void khan(int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        res.push_back(cur);
        for(int child:graph[cur]){
            in[child]--;
            if(in[child]==0){
                q.push(child);
            }
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1);
    in.resize(n+1,0);
    res.resize(n+1);
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        in[b]++;
    }
    khan(n);
    for(int i=0;i<n;i++){
        cout<<res[i]<<" ";
    }
}