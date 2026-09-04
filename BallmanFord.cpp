#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<vector<int>>edge;
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        int u,v,weight;
        cin>>u>>v>>weight;
        vector<int> temp = {u, v, weight};
        edge.push_back(temp);
    }
    int dist[n];
    for(int i=0;i<n;i++)
    dist[i]=1e9;
     int source;
     cin>>source;
    dist[source]=0;

    for(int j=1;j<=n-1;j++)
    {    
        for(int i=0;i<n;i++){
        if(dist[edge[i][0]]+edige[i][2]<dist[edge[i][1]]){
         dist[edge[i][1]]=  dist[edge[i][0]]+edge[i][2]; 
        }
        }
              
    }

    for(int i=0;i<n;i++)
    cout<<dist[i]<<" ";
    return 0;
}
//tc->O(n*m)
//sc->O(n+m);