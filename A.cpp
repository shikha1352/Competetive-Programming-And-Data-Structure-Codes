#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
void solve() {
        ll n,k;
        cin >> n>>k;
        vector<int> a(n);
        vector<int> b(n);
        
        for(int i=0;i<n;i++)
            cin>>a[i];
         
        for(int i=0;i<n;i++)
            cin>>b[i];
        ll cnt=0;
        int i=0;
        while(cnt<k){
            if(b[i]==1){
                a[i]+=1;
                cnt++;
                
            }
            i++;
            if(i==n){
                i=0;
            }
        }
        ll x= *max_element(a.begin(),a.end());
        ll y=0;
        if(n%2==0){
            y=n/2;
        }
        else if(n%2==1){
            y=n/2+1;
        }
        cout<<x+a[y-1]<<endl;
}
int32_t main() {

    ll t;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
