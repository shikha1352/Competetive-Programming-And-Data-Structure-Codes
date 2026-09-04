#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10001];
int visited[10001];
stack<int>st;

void dfs(int node){
    visited[node]=1;
    
    for(int i=0;i<adj[node].size();i++)
    {
        int child=adj[node][i];
        if(visited[child]==0)
        {
            dfs(child);

        }
    }
     st.push(node);
}


int main()
{
    int n,m;
    
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        
    }
     memset(visited,0,sizeof(visited));
   
    for(int i=1;i<=n;i++)
    {
        if(visited[i]==0)
        {
            dfs(i);
        }
    }
    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

  

    return 0;
}