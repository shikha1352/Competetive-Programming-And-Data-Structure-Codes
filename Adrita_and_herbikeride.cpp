#include<bits/stdc++.h>
using namespace std;
#define ll long  long
map<ll,vector<pair<ll,ll>>>graph;
ll val[1000005];
ll n,m,s,d;
void bfs(int s){
    queue<ll>q;
    q.push(s);

    for(int i=1;i<=n;i++){
        val[i]=1e18;
    }
    val[s]=0;
    while(!q.empty()){
        ll current=q.front();
        q.pop();
        for(auto u:graph[current]){
            if(u.first==d){
                if(val[current]+u.second<val[d]){
                    val[d]=val[current]+u.second;
                }
                else
                continue;
            }
            else{
                if(val[u.first]>val[current]+u.second){
                    val[u.first]=val[current]+u.second;
                    q.push(u.first);

                }
            }
        }
    }
}
int main(){
    cin>>n>>m>>s>>d;
    while(m--){
        ll a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w+12});
        graph[b].push_back({a,w+12});
    }
    bfs(s);
    cout<<val[d]<<endl;
}