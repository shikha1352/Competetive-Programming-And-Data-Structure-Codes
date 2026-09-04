#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
       int n,k,d,w;
       cin>>n>>k>>d>>w;
       vector<int>a(n);
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       int valid,ans=0,rem=k;
       for(int i=0;i<n;i++){
        if(i==0 || valid<a[i] || rem<1){
            ans++;
            rem=k;
            valid=a[i]+d+w;
        }
        rem--;
       }
       cout<<ans<<endl;
    }
    return 0;
}
