#include <bits/stdc++.h>
using namespace std;
vector<int> graph[1000001];
vector<int> g[1000001];
int vis[1000001];
stack<int> st;
void dfs(int node)
{
    vis[node] = 1;
    for (int child : graph[node])
    {
        if (vis[child] == 0)
        {
            dfs(child);
        }
       
    }
     st.push(node);
}
    
void dfs2(int node)
{
    vis[node] = 1;
    for (int child : g[node])
    {
        if (vis[child] == 0)
        {
            dfs2(child);
        }
    }
    
}

int main()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0)
        {
            dfs(i);
        }
    }
    int scc=0;
    for(int i=0;i<n;i++){
        vis[i]=0;
    }
    for(int i=0;i<n;i++){
        cout<<st.top()<<" ";
        st.pop();
   while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (vis[node] == 0) {
        scc++;
        dfs2(node);
    }
}
while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (vis[node] == 0) {
        scc++;
        dfs2(node);
    }
}

   cout<<scc<<endl;

}
}