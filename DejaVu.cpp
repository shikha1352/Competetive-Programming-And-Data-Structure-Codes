#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin>>t;
    while(t--)
    {
        ll n,q;
        cin>>n>>q;
        vector<ll>a(n);
        vector<ll>x;
        for(ll i=0; i<n; i++)
        {
            cin>>a[i];
        }
        for(int i=0;i<q;i++){
            int querry;
            cin>>querry;
            if(x.empty() || x.back()>querry)
                x.push_back(querry);
        }
        for(ll i=0; i<n; i++)
        {

            for (auto it:x)
            {
                if (a[i] % (1 << it) == 0) {
                        it=it-1;
                a[i] += (1 << (it));
            }
            }
        }
        for(ll i=0; i<n; i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

}
