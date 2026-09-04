#include <bits/stdc++.h>
using namespace std;
#define int long long
bool f = false;
int c = 0;
void lpsFind(vector<int>& l, const vector<int>& p) {
    int pfx = 0, sfx = 1;

    while (sfx < p.size()) {
        if (p[pfx] == p[sfx]) {
            l[sfx] = pfx + 1;
            pfx++;
            sfx++;
        } else {
            if (pfx == 0) {
                l[sfx] = 0;
                sfx++;
            } else {
                pfx = l[pfx - 1];
            }
        }
    }
}
void findNo(const vector<int>& l, const vector<int>& s, const vector<int>& p, vector<int>& a) {
    int fIdx = 0, sIdx = 0;

    while (fIdx < s.size()) {
        if (s[fIdx] == p[sIdx]) {
            fIdx++;
            sIdx++;
            if (sIdx == p.size()) {
                a.push_back(fIdx - sIdx + 1);
                sIdx = l[sIdx - 1];
            }
        } else {
            if (sIdx != 0) {
                sIdx = l[sIdx - 1];
            } else {
                fIdx++;
            }
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> b[i];
    }
    int ans;
    if (M == 1)
        ans = N;
    else if (N < M)
        ans = 0;
    else {
        vector<int> s(N - 1), p(M - 1);
        for (int i = 0; i < N - 1; i++) {
            s[i] = a[i + 1] - a[i];
        }

        for (int i = 0; i < M - 1; i++) {
            p[i] = b[i + 1] - b[i];
        }
        vector<int> l(p.size(), 0);
        lpsFind(l, p);
        vector<int> a;
        findNo(l, s, p, a);
        ans = a.size();
    }
    cout << ans << '\n';
    return 0;
}
