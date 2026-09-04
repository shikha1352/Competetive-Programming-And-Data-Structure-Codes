#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> st, lazy;
void build(int si, int ss, int se) {
    if (ss == se) {
        st[si] = 0;
        return;
    }
    int mid = (ss + se) / 2;
    build(2 * si, ss, mid);
    build(2 * si + 1, mid + 1, se);
    st[si] = st[2 * si] + st[2 * si + 1];
}

void propagate(int si, int ss, int se) {
    if (lazy[si] != 0) {
        st[si] += (se - ss + 1) * lazy[si];
        if (ss != se) {
            lazy[2 * si] += lazy[si];
            lazy[2 * si + 1] += lazy[si];
        }
        lazy[si] = 0;
    }
}

void update(int si, int ss, int se, int qs, int qe, int val) {
    propagate(si, ss, se);
    if (ss > qe || se < qs) {
        return;
    }
    if (ss >= qs && se <= qe) {
        st[si] += (se - ss + 1) * val;
        if (ss != se) {
            lazy[2 * si] += val;
            lazy[2 * si + 1] += val;
        }
        return;
    }
    int mid = (ss + se) / 2;
    update(2 * si, ss, mid, qs, qe, val);
    update(2 * si + 1, mid + 1, se, qs, qe, val);
    st[si] = st[2 * si] + st[2 * si + 1];
}

int query(int si, int ss, int se, int qs, int qe) {
    propagate(si, ss, se);
    if (ss > qe || se < qs) {
        return 0;
    }
    if (ss >= qs && se <= qe) {
        return st[si];
    }
    int mid = (ss + se) / 2;
    return query(2 * si, ss, mid, qs, qe) + query(2 * si + 1, mid + 1, se, qs, qe);
}

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        st.assign(4 * n + 1, 0);
        lazy.assign(4 * n + 1, 0);
        build(1, 1, n);
        while (c--) {
            int type;
            cin >> type;
            if (type == 0) {
                int p, q, v;
                cin >> p >> q >> v;
                update(1, 1, n, p, q, v);
            } else {
                int p, q;
                cin >> p >> q;
                cout << query(1, 1, n, p, q) << endl;
            }
        }
    }
    return 0;
}
