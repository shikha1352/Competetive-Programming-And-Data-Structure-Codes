#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+9;
int grundy[N];
int n,m;
int a[35];
//int vis[35];
int calmex(int vis[]){
	int mex=0;
	while(vis[mex])
		mex++;
	return mex;
}
int sg(int x){
	if(x<a[0] || x==0)
		return 0;
	if(grundy[x]!=-1)
		return grundy[x];
	int vis[35];
    memset(vis,0,sizeof (vis));
	for(int i=0;i<m;i++){
		if(a[i]<=x){
			vis[sg(x-a[i])]=1;
		}
	}
	grundy[x]=calmex(vis);
	return grundy[x];

}
int32_t main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif 

	int t;
	cin>>t;
	while(t--)
	{
		memset(grundy,-1,sizeof(grundy));
        //int n,m;
        cin>>n>>m;
        //int a[n];
        for(int i=0;i<m;i++){
        	cin>>a[i];
        }
        sort(a,a+m);
        int xs=0;
        for(int i=0;i<n;i++)
        {
        	int x;
        	cin>>x;
        	xs^=sg(x);
        }
        if(xs)
        	cout<<"Ada"<<'\n';
        else cout<<"Vinit"<<'\n';
	}
}