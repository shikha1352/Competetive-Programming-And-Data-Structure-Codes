#include <bits/stdc++.h>
using namespace std;
#define int long long 
const int mod = 1e18+1;
vector<int> ar;
int32_t main() {
    int n;
    cin >> n;
    ar.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> ar[i];
    }

    vector<int> temp(ar.begin(), ar.end());
    sort(temp.begin(), temp.end());

    vector<int> b1(n), b2(n);
    b1[0] = ar[0] % mod;
    b2[0] = temp[0] % mod;

    for (int i = 1; i < n; i++) {
        b1[i] = (ar[i] + b1[i - 1]) % mod;
        b2[i] = (temp[i] + b2[i - 1]) % mod;
    }

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        int sum = 0;
        int l, r;
        cin >> l >> r;
        if (type == 1) {
            if (l > 1) {
                sum = (b1[r - 1] - b1[l - 2] + mod) % mod;
            } else {
                sum = b1[r - 1];
            }
        } else {
            if (l > 1) {
                sum = (b2[r - 1] - b2[l - 2] + mod) % mod;
            } else {
                sum = b2[r - 1];
            }
        }
        cout << sum << endl;
    }
    return 0;
}
