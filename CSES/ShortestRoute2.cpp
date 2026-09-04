
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll INF = 1000000000000;
ll dist[510][510];
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
                if(i==j){
                    dist[i][j]=0;
                }
                else
                dist[i][j]=INF;
            
        }
    }
    while(m--){
        ll a,b,w;
        cin>>a>>b>>w;
        dist[a][b]=min(dist[a][b],w);
        dist[b][a]=min(dist[b][a],w);
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
            }
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        if(dist[x][y]<INF)
        cout<<dist[x][y]<<endl;
        else
        cout<<"-1"<<endl;
        
    }

}