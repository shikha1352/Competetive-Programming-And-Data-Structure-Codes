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
    int n; 
    cin>>n;
    string s; 
    cin>>s;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(s[i]=='U')
            cnt++;
    }
    if(cnt%2==0) 
        no;
    else 
        yes;
    
    
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
