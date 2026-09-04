#include<bits/stdc++.h>
using namespace std;
vector<int>graph[2000001];
vector<int>res;
int in[2000001];
void kahn(int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int curr=q.front();
        res.push_back(curr);
        q.pop();
        for(int child:graph[curr]){
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
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        in[b]++;

    }
    kahn(n);
    if(res.size()!=n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for(int i=0;i<res.size();i++){
            cout<<res[i]<<" ";
        }
        cout<<endl;
    }
}