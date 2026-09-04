#include <iostream>
#include <bitset>
using namespace std;

struct TrieNode {
    TrieNode* nxt[2];
    int cnt, num;
    TrieNode() {
        nxt[0] = nullptr;
        nxt[1] = nullptr;
        cnt = num = 0;
    }
};

TrieNode* rt;

void ins(int x) {
    bitset<32> b(x);

    TrieNode* cur = rt;
    for (int i = 31; i >= 0; --i) {
        int n = b[i];
        if (!cur->nxt[n]) {
            cur->nxt[n] = new TrieNode();
        }
        cur = cur->nxt[n];
        ++cur->cnt;
    }

    cur->num = x;
}

void rem(int x) {
    bitset<32> b(x);

    TrieNode* cur = rt;
    for (int i = 31; i >= 0; --i) {
        int n = b[i];
        cur = cur->nxt[n];
        --cur->cnt;
    }
}

int fnd(int x) {
    bitset<32> b(x);

    TrieNode* cur = rt;
    for (int i = 31; cur != nullptr && i >= 0; --i) {
        int n = b[i];
        if (n == 0) {
            if (cur->nxt[1] != nullptr && cur->nxt[1]->cnt > 0) {
                cur = cur->nxt[1];
            } else {
                cur = cur->nxt[0];
            }
        } else {
            if (cur->nxt[0] != nullptr && cur->nxt[0]->cnt > 0) {
                cur = cur->nxt[0];
            } else {
                cur = cur->nxt[1];
            }
        }
    }

    if (cur == nullptr) {
        return x;
    }
    return max(x ^ cur->num, x);
}

int main() {
    rt = new TrieNode();

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        char p;
        int x;
        cin >> p >> x;

        if (p == '+') {
            ins(x);
        } else if (p == '-') {
            rem(x);
        } else {
            cout << fnd(x) << endl;
        }
    }

    return 0;
}