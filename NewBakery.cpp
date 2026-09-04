#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod=1e18+7;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n,a,b;
        cin>>n>>a>>b;
        ll ans=0;
        if(b<a){
            ans=(n*a);
            cout<<ans<<endl;
            continue;
        }
        ll i=1;
        ll cnt=b-a;
        if(cnt>=n){
            ans=n*b;

            ll diff=(n*(n-1))/2;
            ans-=diff;
            cout<<ans<<endl;
            continue;

        }
        ans=cnt*b;
        ll diff=(cnt*(cnt-1))/2;
        ans-=diff;
        ll k=(n-cnt)*a;
        cout<<ans+k<<endl;
    }
    return 0;
}