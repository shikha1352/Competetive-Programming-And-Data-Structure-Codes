#include<bits/stdc++.h>
using namespace std;
#define ll long long

int numSteps(string s) {
    ll cnt = 0;
    while (s != "1") {
        if (s.back() == '0') {
            // If the last character is '0', remove it (divide by 2)
            s.pop_back();
        } else {
            // If the last character is '1', add 1 to the binary number
            int i = s.size() - 1;
            while (i >= 0 && s[i] == '1') {
                s[i] = '0';
                i--;
            }
            if (i >= 0) {
                s[i] = '1';
            } else {
                s.insert(s.begin(), '1');
            }
        }
        cnt++;
    }
    return cnt;
}

int32_t main() {
    string s;
    cin >> s;
    ll n = numSteps(s);
    cout << n << endl;
    return 0;
}
