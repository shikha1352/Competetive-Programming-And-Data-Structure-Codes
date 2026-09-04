#include<bits/stdc++.h>
using namespace std;
int n, m;
vector<int> graph[200002];
int vis[200002];
int parnt[200002];
int p, q;
bool dfs(int node, int par) {
    vis[node] = 1;
    parnt[node]=par;
    for (auto child : graph[node]) {
        if (vis[child] == 0) {
            if (dfs(child, node) == true) {
                return true;
            }
        } else {
            if (child != par) {
               p=child;
               q=node;
                return true;
            }
        }
    }
    return false; 
}

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    bool b;
    for (int i = 1; i <= n; i++) {
        if(vis[i]==0){
        b = dfs(i, -1);
        if (b == true) {
            break;
        }
        }
    }
    vector<int>path;
    if (b == true) {
        while(q!=parnt[p]){
            path.push_back(q);
            q=parnt[q];
        }
        cout<<path.size()+1<<endl;
        reverse(path.begin(),path.end());
        for(int i=0;i<path.size();i++){
            cout<<path[i]<<" ";
        }
        cout<<path[0]<<endl;
        
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}
