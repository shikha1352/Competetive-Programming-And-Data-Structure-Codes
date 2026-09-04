#include<bits/stdc++.h>
using namespace std;
bool compare(const pair<pair<int, int>, int>& a1, const pair<pair<int, int>, int>& a2) {
    if (a1.first.first != a2.first.first) {
        return a1.first.first < a2.first.first;
    }
    return a1.first.second < a2.first.second;
}
vector<int> suffix(const string &s) {
    int n = s.size();
    vector<int> p(n), c(n);
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
    int k = 0;
    while ((1 << k) < n) {
        vector<pair<pair<int, int>, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
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
        k++;
    }

    return p;
}
int lower_bound_suffix(const string &s, const vector<int> &sa, const string &pattern) {
    int n = s.size(), m = pattern.size();
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (s.compare(sa[mid], m, pattern) >= 0) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return res;
}
int upper_bound_suffix(const string &s, const vector<int> &sa, const string &pattern) {
    int n = s.size(), m = pattern.size();
    int l = 0, r = n - 1, res = -1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (s.compare(sa[mid], m, pattern) > 0) {
            r = mid - 1;
        } else {
            res = mid;
            l = mid + 1;
        }
    }
    return res;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    S += "$";
    int N = S.size();
    vector<int> sa = suffix(S);
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int lb = lower_bound_suffix(S, sa, x);
        if (lb == -1 || S.compare(sa[lb], x.size(), x) != 0) {
            cout << 0 << endl;
            continue;
        }
        int ub = upper_bound_suffix(S, sa, x);
        cout << ub - lb + 1 << endl;
    }
    return 0;
}
