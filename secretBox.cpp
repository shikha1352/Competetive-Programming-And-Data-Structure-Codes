#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int x,y,z,k;
		int ans=0;
		cin>>x>>y>>z>>k;
		for(int i=1;i<=x;i++){
			for(int j=1;j<=y;j++){
				if(i*j>k){
					continue;
				}
				if(k%(i*j)){
					continue;
				}
				int l=k/(i*j);
				if(l>z){
					continue;
				}
				int c=(x+1-i)*(y+1-j)*(z+1-l);
				ans=max(ans,c);
			}
		}
		cout<<ans<<endl;
	}
}
