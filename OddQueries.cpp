#include<bits/stdc++.h>
using namespace std;
#define int long long
int const mod=1e18+7;
int32_t main() {
    int t;
    cin>>t;
    while(t--){
    int n, q;
    cin >> n >> q;
    vector<int> v(n);
    vector<int> sum(n + 1, 0); 
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + v[i - 1];
        sum[i]=sum[i]%mod;
    }

    while (q--) {
        int result=0;
        int l, r, k;
        cin >> l >> r >> k;
        l--; r--; 
        int range_sum = sum[r + 1] - sum[l];
        result = ((sum[n] - range_sum) + k * (r - l + 1))%mod;
        if(result%2==0)
        cout << "NO" << endl;
        else{
            cout<<"YES"<<endl;
        }
    }
    }
    return 0;
}
