#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        vector<ll>a;
        vector<ll>b;
        ll n, m;
        cin >> n >> m;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin>>x;
            a.push_back(x);
        }
        for (ll i = 0; i < m; i++)
        {
            ll y;
            cin>>y;
            b.push_back(y);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        reverse(b.begin(),b.end());
        ll ans = 0;
        ll s=0,e=n-1,l=0,h=m-1;
        while(s<=e){
            ll i=abs(a[s]-b[l]);
            ll j=abs(a[e]-b[h]);
            if(i>j){
                ans+=i;
                s++;
                l++;
               
            }
            else{
                ans+=j;
                h--;
                e--;
                
            }
        }
        cout<<ans<<endl;
    }
}