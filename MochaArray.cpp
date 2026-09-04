#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        if (a[0] == 1) {
            cout << "YES" << endl;
            continue;
        }

        int prime_count = 0;
        vector<int> primes;
        for (int i = 0; i < n; ++i) {
            if (isPrime(a[i])) {
                primes.push_back(a[i]);
                ++prime_count;
                if (prime_count > 2) {
                    break;
                }
            }
        }

        if (prime_count > 2) {
            cout << "NO" << endl;
        } else if (prime_count == 2) {
            int p = primes[0], q = primes[1];
            bool all_divisible = true;
            for (int i = 0; i < n; ++i) {
                if (a[i] % p != 0 && a[i] % q != 0) {
                    all_divisible = false;
                    break;
                }
            }
            if (all_divisible) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}
