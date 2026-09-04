#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>graph[2000002];
int visited[2000002];
int dist[2000002];
int parnt[2000002];
 bool bfs(){
    visited[1] = 1;
    dist[1] = 0;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int current = q.front();
        q.pop();
        if (current == n){
            return true;
        }
        for (int child : graph[current]){
            if (visited[child] == 0){
                dist[child] = dist[current] + 1;
                parnt[child] = current;
                visited[child] = 1; // Mark child as visited here
                q.push(child);
            }
        }
    }
    return false;
}

int main(){
    int m;
    cin>>n>>m;
    while(m--){
        int a,b;
        cin>>a>>b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    if(bfs()){

    vector<int>pq;
    int path=n;
    while(path!=0){
        pq.push_back(path);
        path=parnt[path];
    }
    cout<<pq.size()<<endl;
    reverse(pq.begin(),pq.end());
    for(int res:pq){
        cout<<res<<" ";
    }
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }

}