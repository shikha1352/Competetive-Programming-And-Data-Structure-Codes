#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int flag=0;
void bfs(int a,int b){
    map<ll,ll>vis;
    map<ll,ll>p;
    queue<ll>q;
    q.push(a);
    while(!q.empty()){
        ll cur=q.front();
        q.pop();
        vis[cur]=1;
        ll v=2*cur;
        if(vis[v]==0 && v<=b){
            q.push(v);
            p[v]=cur;
            vis[v]=1;
            if(v==b){
                flag=1;
                break;
            }
        }
        ll vv=10*cur+1;
        if(vis[vv]==0 && vv<=b){
            vis[vv]=1;
            q.push(vv);
            p[vv]=cur;
            if(vv==b){
                flag=1;
                break;
            }
        }
    }
    if(flag==1){
        vector<ll>path;
        ll pp=p[b];
        path.push_back(pp);
        while(pp!=a){
            pp=p[pp];
            path.push_back(pp);
            
        }
        reverse(path.begin(),path.end());
        cout<<path.size()+1<<endl;
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<b<<endl;
        cout<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
int main(){
    cin>>n>>m;
    bfs(n,m);
}