#include <bits/stdc++.h>
using namespace std;
#define int long long

bool compare(const pair<pair<int, int>, int>& a1, const pair<pair<int, int>, int>& a2) {
    if (a1.first.first != a2.first.first) {
        return a1.first.first < a2.first.first;
    }
    return a1.first.second < a2.first.second;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    string s;
    int k=2; // Minimum number of occurrences
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);

    // Initial sorting by first character
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {s[i], i};
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }

    int curr_k = 0;
    while ((1 << curr_k) < n) {
        vector<pair<pair<int, int>, int>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << curr_k)) % n]}, i};
        }

        sort(a.begin(), a.end(), compare);

        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        curr_k++;
    }

    // Build LCP array
    vector<int> lcp(n);
    curr_k = 0;
    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        rank[p[i]] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int j = p[rank[i] - 1];
        while (s[i + curr_k] == s[j + curr_k]) {
            curr_k++;
        }
        lcp[rank[i]] = curr_k;
        if (curr_k > 0) {
            curr_k--;
        }
    }
    //int i=count(s.begin(),s.end(),s[0]);
    //cout<<i<<endl;
    // Find the longest substring that occurs >= k times
    int maxLen = 0;
    int index = -1;

    for (int i = 1; i <= n - k; i++) { // Sliding window over LCP array
        int minLcp = lcp[i];
        for (int j = i; j < i + k - 1; j++) {
            minLcp = min(minLcp, lcp[j]);
        }
        if (minLcp > maxLen) {
            maxLen = minLcp;
            index = p[i];
        }
    }
    if (maxLen == 0) {
        cout << -1 << endl;
    } else {
        cout << s.substr(index, maxLen) << endl;
    }

    return 0;
}