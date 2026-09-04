#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        ll l,r;
        cin>>l>>r;
        bool flag=0;
        ll ans=INT_MIN;
        ll cnt=0;
        for(int i=l;i<=r;i++){
            string s=to_string(i);
            ll mx=-1,mn=10;
            for(int j=0;j<s.size();j++){
                mx = max(mx,(ll)s[j]-'0');
                mn=min(mn,(ll)s[j]-'0');
            }
            if((mx-mn)==9){
                cnt=i;
                break;
            }
            if(mx-mn>=ans){
            ans=(mx-mn);
            cnt=i;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}
