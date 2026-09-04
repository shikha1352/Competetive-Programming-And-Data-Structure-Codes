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
   int x;
   cin>>x;
   ll m;
   cin>>m;
   int ans=0;for(int y=1;y<=2*x && y<=m;y++){
        if(x==y)
            continue;
        int xy=x^y;
        if(x%xy==0 || y%xy==0)
            ans++;
   }
   cout<<ans<<endl;
    
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
