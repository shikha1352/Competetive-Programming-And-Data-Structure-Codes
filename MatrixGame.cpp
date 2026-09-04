#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int32_t main() {
    init();
    int t;
    int cs = 0;
    cin >> t;
    while (t--) {
        cs++;
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                sum += x;
            }
            ans ^= sum;
        }
        cout << "Case " << cs << ": ";
        if (ans) {
            cout << "Alice" << '\n';
        } else {
            cout << "Bob" << '\n';
        }
    }
    return 0;
}
