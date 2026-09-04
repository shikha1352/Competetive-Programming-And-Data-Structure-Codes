#include<bits/stdc++.h>
using namespace std;
vector<int>graph[1000001];
int in[100];
vector<int>result;
void khan(int n){
    queue<int>q;
    for(int i=1;i<=n;i++){
        if(in[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int current=q.front();
        result.push_back(current);
        for(int child:graph[current]){
            in[child]--;
            if(in[child]==0){
                q.push(child);
            }
        }
    }
    cout<<"Top SOrt is:";
    for(int i=1;i<=n;i++){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}
int main(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        in[i]=0;
    }
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        in[b]++;
    }
    khan(n);
}