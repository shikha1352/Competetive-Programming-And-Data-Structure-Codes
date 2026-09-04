#include<bits/stdc++.h>
using namespace std;
vector<vector<int>>graph;
vector<int>vis;
int32_t main(){
    int n,m,sum=0;
    cin>>n>>m;
    graph.resize(n+1);
    vis.resize(n,0);
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,0});
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int dis=it.first;
        if(vis[node]==1){
            continue;
        }
        vis[node]=1;
        sum+=dis;
        for(auto it:graph[node]){
           int adjnode=it[0];
           int enw=it[1];
        
        if(vis[adjnode]==0){
            pq.push({edw,adjnode});
        }
        }

    }
    cout<<sum<<endl;
}