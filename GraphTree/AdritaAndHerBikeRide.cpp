#include<bits/stdc++.h>
using namespace std;
#define ll long long
map<ll,vector<pair<ll,ll>>>adj;
ll val[100005];
ll V,E,src,des;
void bfs(ll x){
	for(ll i=1;i<=V;i++)
		val[i]=1e18;
	ll current;
	queue<ll>q;
	q.push(x);
	val[x]=0;
	while(!q.empty()){
		current=q.front();
		q.pop();
		for(auto u:adj[current]){
			if(u.first==des){
				if(val[current]+u.second<val[des]){
					val[des]=val[current]+u.second;
				}
				else continue;
			}
		    if(val[u.first]>val[current]+u.second){
				q.push(u.first);
				val[u.first]=val[current]+u.second;
			}
		}
	}
}

int main()
{
    
    ll t;
    cin>>t;
    while(t--)
    {
        cin>>V>>E>>src>>des;
        adj.clear();
        for(ll i=0;i<E;i++)
        {
            ll x,y,z;
            cin>>x>>y>>z;
            adj[x].push_back({y,z+12});
            adj[y].push_back({x,z+12});
        }
        bfs(src);
        ll ans=val[des];
        cout<<ans<<endl;
    }
}