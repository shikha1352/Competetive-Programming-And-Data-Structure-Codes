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
    ll n,m,k;
    cin>>n>>m>>k;
    string s;
    cin>>s;
    int ans=0;
    int cnt=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0'){
            cnt++;
            if(cnt==m){
                ans++;
                cnt=0;
                i+=k-1;
            }
        }
        else
            cnt=0;
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
