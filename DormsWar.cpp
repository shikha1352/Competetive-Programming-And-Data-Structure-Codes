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

    // Map to store "special" characters
    unordered_map<char, int> m;
    for (int i = 0; i < k; i++) {
        char x;
        cin >> x;  // Read a character, not an integer
        m[x]++;
    }

    int cnt = 0;
    while (true) {
        unordered_set<int> st;

        // Find positions to remove
        for (int i = 0; i < s.size() - 1; i++) {
            if (m.find(s[i + 1]) != m.end()) {
                st.insert(i);  // Mark index of the character to be removed
            }
        }

        // If no characters are marked for removal, break
        if (st.empty()) {
            break;
        }

        cnt++;
        string ns = "";

        // Construct new string
        for (int i = 0; i < s.size(); i++) {
            if (st.find(i) == st.end()) {
                ns += s[i];  // Keep characters not marked for removal
            }
        }

        s = ns;  // Update string
    }

    cout << cnt << endl;
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
