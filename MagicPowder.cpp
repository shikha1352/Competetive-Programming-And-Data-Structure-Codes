#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    ll s = 0, e = 1e9;
    while (s <= e) {
        ll mid = (s + e) / 2;
        ll cost = 0;
        bool flag = true;
        for (ll i = 0; i < n; i++) {
            ll need = a[i] * mid;
            if (b[i] >= need) {
                continue;
            }
            else
            cost =cost+ (need - b[i]);
            if (cost > k) {
                flag = false;
                break;
            }
        }
        if (flag) {
            s= mid + 1;
        }
         else {
            e = mid - 1;
        }
    }
    cout << s - 1 << endl;
    return 0;
}