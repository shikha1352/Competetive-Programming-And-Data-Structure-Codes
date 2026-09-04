#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;

    unordered_map<char, int> m;
    for (int i = 0; i < k; i++) {
        char x;
        cin >> x;
        m[x]++;
    }
        vector<int>ans;

        for (int i = 0; i < s.size(); i++) {
            if(m.find(s[i+1])!=m.end()){
                ans.push_back(1);
            }
            else{
                ans.push_back(0);
            }
        }
        int cnt=0;
        int mx=0;
        int cnt1=0;
        for(int i=0;i<ans.size();i++){
            if(ans[i]==0){
                cnt++;
            }
            else{
                cnt1++;
                mx=max(cnt,mx);
                cnt=0;
            }
        }
        if(cnt1==0){
            cout<<mx<<endl;
            return;
        }

    cout << mx+1 << endl;
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
