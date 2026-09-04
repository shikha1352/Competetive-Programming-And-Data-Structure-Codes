#include<bits/stdc++.h>
using namespace std;
#define INF 1e9
int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>v[n];
        int dist[n];
        int cost[n][n];
        memset(cost,0,sizeof(cost));
        for(int i=0;i<n;i++){
            dist[i]=INF;
             v[i].clear();
        }
       
        for(int i=0;i<m;i++){
            int a,b,w;
            cin>>a>>b>>w;
            if(cost[a][b]){
                cost[a][b]=cost[b][a]=min(cost[a][b],w);
            }
            else{
                v[a].push_back(b);
                v[b].push_back(a);
                cost[a][b]=cost[b][a]=w;
            }
        }
        int x;
        cin>>x;
        dist[x]=0;
        queue<int>pq;
        queue<int>empty_pq;
        swap(pq,empty_pq);
        pq.push(x);
        while(!pq.empty()){
            int start=pq.front();
            pq.pop();
            for(int i=0;i<v[start].size();i++){
                int current=v[start][i];
                int maxcost=max(dist[start],cost[start][current]);
                if(dist[current]>maxcost){
                        dist[current]=maxcost;
                        pq.push(current);
                }
            }
        }
        cout<<"Case "<<cs++<<":"<<endl;
        for(int i=0;i<n;i++){
            if(dist[i]==INF){
                cout<<"Impossible"<<endl;
            }
            else{
                cout<<dist[i]<<endl;
            }
        }
    }
}