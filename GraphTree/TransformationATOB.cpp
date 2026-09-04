#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll flg = 0;
void bfs(ll a, ll b)
{
    queue<ll> q;
    q.push(a);
    map<ll,ll> visit;
    map<ll,ll> par;
    while (!q.empty())
    {
        ll u = q.front();
        q.pop();
        ll v = 2 * u;
        visit[u] = 1;
        if (visit[v] == 0 & v <= b)
        {
            visit[v] = 1;
            par[v] = u;
            q.push(v);
            if (v == b)
            {
                flg = 1;
                break;
            }
        }
        ll vv = 10 * u + 1;
        if (visit[vv] == 0 & vv <= b)
        {
            visit[vv] = 1;
            par[vv] = u;
            q.push(vv);
            if (vv == b)
            {
                flg = 1;
                break;
            }
        }
    }
    if(flg){
        vector<ll>ans;
        ll p=par[b];
        ans.push_back(p);
        while(p!=a){
            p=par[p];
            ans.push_back(p);
        }
        cout<<"YES"<<endl;
        cout<<ans.size()+1<<endl;
        for(ll i=ans.size()-1;i>=0;i--){
            cout<<ans[i]<<" ";
        }
        cout<<b<<endl;
    }
    else cout<<"NO"<<endl;
}
int main()
{
    ll a, b;
    cin >> a >> b;
    bfs(a, b);
    return 0;
}

