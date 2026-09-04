#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const mod=1000000007;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll ans=n*(n-1);
        ans%=mod;
        for(ll i=1;i<=n;i++){
            ans*=i;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
}