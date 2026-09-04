#include<bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[26];
    bool flag=false;

    bool containsKey(char ch) {
        return (links[ch-'a'] != NULL);
    }

    Node* get(char ch) {
        return (links[ch-'a']);
    }

    void put(char ch, Node* node) {
        links[ch-'a'] = node;
    }

    void setend() {
        flag = true;
    }

    bool isEnd() {
        return flag;
    }
};

void insert(string word, Node* root) {
    Node* node = root;
    for(int i = 0; i < word.size(); i++) {
        if(!node->containsKey(word[i])) {
            node->put(word[i], new Node());
        }
        node = node->get(word[i]);
    }
    node->setend();
}

bool search(string word, Node* root) {
    Node* node = root;
    for(int i = 0; i < word.size(); i++) {
        if(!node->containsKey(word[i])) {
            return false;
        }
        node = node->get(word[i]);
    }
    return node->isEnd();
}

bool startwith(string word, Node* root) {
    Node* node = root;
    for(int i = 0; i < word.size(); i++) {
        if(!node->containsKey(word[i])) {
            return false;
        }
        node = node->get(word[i]);
    }
    return true;
}

int main() {
    Node* root = new Node();
    int n;
    cin >> n;

    // Insert words
    while(n--) {
        string s;
        cin >> s;
        insert(s, root);
    }

    // Reset value of n
    cin >> n;

    // Search words
    while(n--) {
        string s;
        cin >> s;
        cout << search(s, root) << endl;
    }

    // Reset value of n
    cin >> n;

    // Prefix search
    while(n--) {
        string s;
        cin >> s;
        cout << startwith(s, root) << endl;
    }

    delete root; // Free memory
    return 0;
}
