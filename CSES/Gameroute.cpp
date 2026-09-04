#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m;
vector<vector<int>>graph;
vector<int>in;
vector<int>cnt;
void topsort(){
    queue<int>q;
    for(int i=2;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            --in[v];
            if(in[v]==0 && v!=1){
                q.push(v);
            }
        }

    }
    q.push(1);
    cnt[1]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int v:graph[u]){
            --in[v];
            cnt[v]=(cnt[v]+cnt[u])%mod;
            if(in[v]==0 && v!=1){
                q.push(v);
            }
        }

    }
}
int32_t main(){
    cin>>n>>m;
    graph.resize(n+1);
    in.resize(n+1);
    cnt.resize(n+1);
    for(int i=1;i<=n;i++){
        in[i]=0;
        cnt[i]=0;
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        in[b]++;
    }
    
    topsort();
    cout<<cnt[n]<<endl;
    
}