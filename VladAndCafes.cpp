#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    unordered_set<int> seen;
    vector<int> unique_elements;

    for (int i = n - 1; i >= 0; i--) {
        if (seen.find(v[i]) == seen.end()) {
            seen.insert(v[i]);
            unique_elements.push_back(v[i]);
        }
    }

    cout << unique_elements.back() << endl;

    return 0;
}
