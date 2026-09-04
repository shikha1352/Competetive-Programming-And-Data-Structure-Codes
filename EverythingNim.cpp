#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;

void solve() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        sum=sum^x;
    }
    if(sum==0){
        cout<<"Bob"<<endl;
    }
    else{
        cout<<"Alice"<<endl;
    }
    
}
int32_t main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
