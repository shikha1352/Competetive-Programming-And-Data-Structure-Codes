#include<bits/stdc++.h>
using namespace std;

const int BLOCK = 1000;

struct query {
    int l, r, i;
};

query Q[200001];
int ar[30001], ans[200001];
int fre[1000001];
int cnt = 0;

bool comp(query a, query b) {
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK;
    return a.r < b.r;
}

void add(int pos) {
    fre[ar[pos]]++;
    if (fre[ar[pos]] == 1)
        cnt++;
}

void remove(int pos) {
    fre[ar[pos]]--;
    if (fre[ar[pos]] == 0)
        cnt--;
}

int main() {
    int n, q;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> ar[i]; 
    }

    cin >> q; 

    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--; 
        Q[i].r--; 
    }

    sort(Q, Q + q, comp);

    int ML = 0, MR = -1;

    for (int i = 0; i < q; i++) {
        int L = Q[i].l;
        int R = Q[i].r;

        while (ML > L) {
            ML--;
            add(ML);
        }
        while (ML < L) {
            remove(ML);
            ML++;
        }
        while (MR > R) {
            remove(MR);
            MR--;
        }
        while (MR < R) {
            MR++;
            add(MR);
        }

        ans[Q[i].i] = cnt;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
