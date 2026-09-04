#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;

void solve() {
    string s;
    cin >> s;
    string x = "hello";
    int j = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == x[j]) {
            j++;
        }
        if (j == x.size()) {
            yes;
            return;
        }
    }
    no; 
}

int32_t main() {
   
    
    solve();
    return 0;
}
