#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;

void solve() {
    string s;
    cin>>s;
    if(s.size()==1){
        cout<<-1<<endl;
        return;
    }
    string x="-1";
    for(int i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1]){
            x=s.substr(i,2);
            break;
        }
    }
    for(int i=0;i<s.size()-2;i++){
        if(x=="-1" && s[i]!=s[i+2]){
            x=s.substr(i,3);
            break;
        }
    }
    cout<<x<<endl;
    
}

int32_t main() {
     #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}