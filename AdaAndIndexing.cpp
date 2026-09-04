#include <bits/stdc++.h>
#include <string>
using namespace std;
struct Node {
    
    Node *children[26];
    int EndOfWord = 0;
    int cntPrefix = 0;
};

Node* getNode() {
    Node* pNode = new Node;

    pNode->EndOfWord = 0;
    for (int i = 0; i < 26; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

void insert(Node* root, string &key) {
    Node* pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
        pCrawl->cntPrefix++;
    }
    pCrawl->EndOfWord++;
}

int startWith(Node* root, string &key) {
    Node* pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (!pCrawl->children[index]) {
            return 0;
        }
        pCrawl = pCrawl->children[index];
    }
    return (pCrawl->cntPrefix);
}

int main() {
    int n, q;
    cin >> n >> q;
    Node* root = getNode();
    while (n--) {
        string key;
        cin >> key;
        insert(root,key);
    }
    while (q--) {
        string word;
        cin >> word;
        int d = startWith(root, word);
        cout << d << endl;
    }
}
