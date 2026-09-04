#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100001;
const int INF = INT_MAX;

int arr[MAXN], st[4 * MAXN];

void buildTree(int si, int ss, int se) {
    if (ss == se) {
        st[si] = arr[ss];
        return;
    }
    int mid = (ss + se) / 2;
    buildTree(2 * si, ss, mid);
    buildTree(2 * si + 1, mid + 1, se);
    st[si] = min(st[2 * si], st[2 * si + 1]);
}

int query(int si, int ss, int se, int qs, int qe) {
    if (ss > qe || se < qs) {
        return INF;
    }
    if (ss >= qs && se <= qe) {
        return st[si];
    }
    int mid = (ss + se) / 2;
    return min(query(2 * si, ss, mid, qs, qe), query(2 * si + 1, mid + 1, se, qs, qe));
}

int main() {
    int t;
    cin >> t;
    int cs = 1;

    while (t--) {
        int n, q;
        cin >> n >> q; 
        for (int i = 1; i <= n; i++) {
            cin >> arr[i];
        }

        buildTree(1, 1, n);

        cout << "Case " << cs++ << ":" << endl;
        while (q--) {
            int l, r;
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << endl;
        }
    }

    return 0;
}
