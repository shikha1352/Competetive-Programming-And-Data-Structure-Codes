#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>a(n);
        for(ll i=0;i<n;i++){
            cin>>a[i];
        }
    if(is_sorted(a.begin(),a.end())){
        cout<<"YES"<<endl;
    }
    else{
    ll last=0;
    vector<ll>ans;
    for(ll i=0;i<n;i++){
        ll v=a[i]/10;
        ll r=a[i]%10;
        if(v>=last && r>=v){
            last=r;
            ans.push_back(v);
            ans.push_back(r);
        }
        else{
            ans.push_back(a[i]);
            last=a[i];
        }
    }
    if(is_sorted(ans.begin(),ans.end())){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    }
}