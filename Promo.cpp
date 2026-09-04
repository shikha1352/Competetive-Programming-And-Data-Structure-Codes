#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
		int n,m;
		cin>>n>>m;
		vector<int>a(n);
		for(int i=0;i<n;i++){
		    cin>>a[i];
		}
        sort(a.begin(),a.end());
        reverse(a.begin(),a.end());
        vector<int>sum(n);
        sum[0]=a[0];
         for(int i=1;i<n;i++){
		        sum[i]=sum[i-1]+a[i];
		    }
		for(int i=1;i<=m;i++){
		    int x,y;
		    cin>>x>>y;
		    if(x==y){
                cout<<sum[x-1]<<endl;
            }
		    else{
                cout<<sum[x-1]-sum[x-1-y]<<endl;
            }
		}
	
}