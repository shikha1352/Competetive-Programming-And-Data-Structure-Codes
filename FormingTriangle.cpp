#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    ll t;
    cin>>t;
    while(t--)
    {
        ll n;
        cin>>n;
        vector<ll>v;
        map<ll,ll>mp;
        for(ll i=0; i<n; i++)
        {
            ll x;
            cin>>x;
            v.push_back(x);
        }
        for(auto it:v){
            mp[it]++;
        }
        ll ans=0;
        sort(v.begin(),v.end());
        for(auto it:mp)
        {
            ll k=it.second;
            ans+=(k*(k-1)*(k-2))/6;
            ll index=lower_bound(v.begin(),v.end(),it.first)-v.begin();
            ans+=(k*(k-1)/2)*index;
        }
        cout<<ans<<endl;
    }
}
