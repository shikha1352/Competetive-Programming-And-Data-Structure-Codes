#include<bits/stdc++.h>
using namespace std;
void ln(int m,int start){
	int k=start;
	for(int i=1;i<=m;i+=2){
		if(k==1){
			cout<<"1 0 ";
		}
		else{
			cout<<"0 1 ";
		}
		k^=1;
	}
}
signed main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int p=1;
		for(int i=1;i<=n;i+=2){
			if(p==1){
				ln(m,1);
				ln(m,0);
			}
			else{
				ln(m,0);
				ln(m,1);
			}
			p^=1;
		}
	}
}