#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll x,n,ans=1;
        cin>>x>>n;
        for(ll i=1;i*i<=x;i++){
            if(x%i==0){
                if((x/i)>=n){
                    ans=max(ans,i);
                }
                if(i>=n){
                    ans=max(ans,(x/i));
                }
            }
        }
        cout<<ans<<endl;
    }
}
