#include<bits/stdc++.h>
using namespace std;
#define mx 100001
vector<pair<int,int>>graph[mx];
int32_t main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,wt;
        cin>>a>>b>>wt;
        graph[a].push_back({b,wt});
        graph[b].push_back({a,wt});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    vector<pair<int,int>>mst;
    vector<int>parnt(n,-1);
    int sum=0;
    pq.push({0,1});
    vector<int>vis(n,0);
    while(!pq.empty()){
        auto it=pq.top();
        pq.pop();
        int node=it.second;
        int w=it.first;
        if(vis[node]==1){
            continue;
        }
        vis[node]=1;
        sum+=w;
        if(parnt[node]!=-1){
            mst.push_back({parnt[node],node});
        }
        for(int i=0;i<graph[node].size();i++){
            auto child=graph[node][i];
            int adjnode=child.first;
            int edw=child.second;
            if(vis[adjnode]==0){
                pq.push({edw,adjnode});
                parnt[adjnode]=node;
            }
        }

    }
    cout<<sum<<endl;
    for(auto it:mst){
        cout<<it.first<<" "<<it.second<<endl;
    }
}