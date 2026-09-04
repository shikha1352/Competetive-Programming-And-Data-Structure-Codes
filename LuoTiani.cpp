#include<bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n>m)
        swap(n,m);
        vector<int>a(n*m);
        for(int i=0;i<n*m;i++){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        int mx1=a[(n*m)-1];
        int mx2=a[(n*m)-2];
        int mn1=a[0];
        int mn2=a[1];
        ll ans1=0;
         ans1=((n*m)-n)*(mx1-mn1);
        for(int i=1;i<n;i++){
            ans1+=(mx2-mn1);
        }
        ll ans2=0;
         ans2=((n*m)-n)*(mx1-mn1);
         for(int i=1;i<n;i++){
            ans2+=(mx1-mn2);
        }
        ll ans=max(ans1,ans2);
        cout<<ans<<endl;
    }
}