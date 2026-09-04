#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
       ll n;
       cin>>n;
       vector<int>a(n);
       map<int,int>mp;
       for(int i=0;i<n;i++){
        cin>>a[i];
        mp[a[i]]++;
       }
       if(n==1){
        cout<<0<<endl;
        continue;
       }
       ll mx=0;
       for(auto it:mp){
          mx=max(mx,(ll)it.second);
       }
       if(mx==1){
        cout<<1<<endl;
        continue;
       }
       ll k=mp.size();
       if(mx==k-1){
        cout<<mx<<endl;
        continue;
       }
       ll p=min(mx,k-1);
       ll q=min(mx-1,k);
       cout<< max(p,q) <<endl; 
    }
    return 0;
}
