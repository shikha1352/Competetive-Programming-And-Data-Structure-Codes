#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
    ll n;
    cin>>n;
    ll even=0,odd=0,ans=0;
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        if(x%2==0){
            even++;
        }
        else{
            odd++;
        }
        ans+=x;
        ll d=odd/3;
        if(even==0 && odd==1){
            d=0;
        }
        else if(odd%3==1){
            d=(odd+2)/3;
        }
        cout<<ans-d<<" ";
    }
    cout<<endl;
    }
    
}