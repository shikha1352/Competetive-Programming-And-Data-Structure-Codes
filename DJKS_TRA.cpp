#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>>graph[10000];
set<pair<int,int>>st;
int main(){
    int n,m;
    cin>>n>>m;
    while(m--){
        int a,b,w;
        cin>>a>>b>>w;
        graph[a].push_back({b,w});
    }
    vector<long long>dist(n+1,INT_MAX);
    st.insert({0,1});
    dist[1]=0;
    while(!st.empty()){
        auto it=st.begin();
        int adjnode=it->second;
        int d=it->first;
        st.erase(it);
        for(pair<int,int>child:graph[adjnode]){
            int node=child.first;
            int w=child.second;
            if(w+d<dist[node]){
                st.erase({dist[node],node});
                dist[node]=w+d;
                st.insert({dist[node],node});
            }
        }

    }
    for(int i=1;i<=n;i++){
        cout<<dist[i]<<endl;
    }

}