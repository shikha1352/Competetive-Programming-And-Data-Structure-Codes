#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int>adj[100001];
int visited[100001];
int ans[100001];
int parent[100001];
 
int32_t main()
{
 
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int x,y;
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
 
    }
    bool flag=true;
    memset(visited,0,sizeof(visited));
    for(int i=1; i<=n; i++)
    {
        if(visited[i]==0)
        {
            queue<int>q;
            visited[i]=1;
            ans[i]=1;
            q.push(i);
            while(!q.empty())
            {
                int node=q.front();
                q.pop();
                for(int i=0; i<adj[node].size(); i++)
                {
                    int child=adj[node][i];
                    if(visited[child]==0)
                    {
                        visited[child]=1;
                        if(ans[node]==1)
                            ans[child]=2;
                        else if(ans[node]==2)
                            ans[child]=1;
                        q.push(child);
 
                    }
                    else if(ans[node]==ans[child]){
                        flag=false;
                        break;
                    }
                }
 
            }
        }
    }
    if(flag)
    {
        for(int i=1; i<=n; i++)
        {
            cout<<ans[i]<<" ";
        }
 
        cout<<endl;
    }
    else
        cout<<"IMPOSSIBLE"<<endl;
 
 
    return 0;
}