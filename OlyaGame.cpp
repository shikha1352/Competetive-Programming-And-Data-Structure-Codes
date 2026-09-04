#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(),v.end()
typedef long long ll;

const int INF=1e9+7;
void solve(){
	int n;
	cin>>n;
	vector<int>a(n);
	vector<int>b(n);
	map<int,int>ma;
	map<int,int>mb;
	for(auto &e:a){
		cin>>e;
		ma[e]++;
	}

	for(auto &f:b){
		cin>>f;
		mb[f]++;
	}
	int ans=0;
	for(auto [v,val]:ma){
		ans=max(ans,ma[v]+mb[v]);
	}
	for(auto [v,val]:mb){
		ans=max(ans,ma[v]+mb[v]);
	}
	cout<<ans<<endl;

}
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

#ifdef LOCAl
	freopen("a.in","r",stdin);
#endif
	int t;
	cin>>t;
	while(t--){
		solve();
		
	}
	return 0;
}
