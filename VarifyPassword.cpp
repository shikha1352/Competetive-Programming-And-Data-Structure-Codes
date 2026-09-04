#include <bits/stdc++.h>
using namespace std;
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool flag = false;
        vector<int> digit;
        vector<char> letter;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                digit.push_back(s[i] - '0');
            } else {
                letter.push_back(s[i]);
            }
        }
        if (is_sorted(digit.begin(), digit.end()) && is_sorted(letter.begin(), letter.end())) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    if (s[i + 1] >= '0' && s[i + 1] <= '9') {
                        flag = true;
                        break;
                    }
                }
            }
            if (flag) {
                cout << "NO" << endl;
            } else {
                cout << "YES" << endl;
            }
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
