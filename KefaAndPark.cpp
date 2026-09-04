#include<bits/stdc++.h>
using namespace std;
int n,m;
int a=0;
vector<int>cat,vis;
vector<vector<int>>g;
void dfs(int node,int k){
    vis[node]=1;
    int f=1;
    if(k>m){
        return;
    }
    for(auto child:g[node]){
        if(!vis[child]){
            f=0;
            dfs(child,k*cat[child]+cat[child]);
        }
    }
    if(f==1){
        a++;
    }
}
int32_t main(){
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    cin>>n>>m;
    cat.resize(n+1);
    for(int i=1;i<=n;i++){
        cin>>cat[i];
    }
    g.resize(n+1);
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vis.resize(n+1,0);
    dfs(1,cat[1]);
    cout<<a<<endl;
}