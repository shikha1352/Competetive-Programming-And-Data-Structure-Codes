#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define lli long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define mod 1000000007
lli getHash(string key){
    lli value=0;
    lli p=31;
    lli p_power=1;
    for(char ch:key){
        value=(value+(ch-'a'+1)*p_power)%mod;
        p_power=(p_power*p)%mod;
    }
    return value;
}
void solve() {
        string key;
        cin>>key;
        cout<<"key: "<<key<<"Hash: "<<getHash(key)<<endl;
}
int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif 
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
