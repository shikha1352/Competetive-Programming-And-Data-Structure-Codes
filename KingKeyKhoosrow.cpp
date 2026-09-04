#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;
int dx[] = {-1,0,+1,0};
int dy[] = {0,+1,0,-1};
void solve() {
    ll n,m;
    cin>>n>>m;
    int g=__gcd(n,m);
    cout<<(n*m)/g<<endl;
    
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
