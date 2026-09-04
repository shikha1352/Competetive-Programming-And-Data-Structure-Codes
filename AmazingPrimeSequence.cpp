#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
const int MX = 1e7 + 9;

int fib[MX];
int pSum[MX];

void init() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

int32_t main() {
    init();

    for (int i = 2; i < MX; i++) {
        fib[i] = i;
    }

    for (int i = 2; i * i < MX; i++) {
        if (fib[i] == i) {
            for (int j = i * i; j < MX; j += i) {
                fib[j] = min(fib[j], i);
            }
        }
    }

    pSum[1] = 0;
    for (int i = 2; i < MX; i++) {
        pSum[i] = pSum[i - 1] + fib[i];
    }

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        cout << pSum[n] << '\n';
    }

    return 0;
}
