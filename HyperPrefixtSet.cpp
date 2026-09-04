#include <bits/stdc++.h>
using namespace std;

const int ALPHABET_SIZE = 2; // Binary strings (0, 1)

// Trie Node structure
struct trieNode {
    bool isEndOfWord;
    int count; // Number of strings passing through this node
    trieNode *children[ALPHABET_SIZE];
};

// Function to create a new trie node
struct trieNode *getNode() {
    struct trieNode *pNode = new trieNode;
    pNode->isEndOfWord = false;
    pNode->count = 0;
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        pNode->children[i] = NULL;
    }
    return pNode;
}

// Insert a binary string into the trie
void insert(trieNode *root, const string &key) {
    struct trieNode *pCrawl = root;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - '0';
        if (!pCrawl->children[index]) {
            pCrawl->children[index] = getNode();
        }
        pCrawl = pCrawl->children[index];
        pCrawl->count++; // Increment count for this node
    }
    pCrawl->isEndOfWord = true;
}

// Recursive function to calculate the maximum prefix goodness
int calculateGoodness(trieNode *node, int depth) {
    if (!node) return 0;

    // Current goodness at this node
    int currentGoodness = depth * node->count;

    // Calculate goodness for child nodes
    int leftGoodness = calculateGoodness(node->children[0], depth + 1);
    int rightGoodness = calculateGoodness(node->children[1], depth + 1);

    // Return the maximum goodness found
    return max({currentGoodness, leftGoodness, rightGoodness});
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int n;
        cin >> n; // Number of binary strings

        struct trieNode *root = getNode();

        // Insert each binary string into the trie
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            insert(root, s);
        }

        // Calculate the maximum prefix goodness
        int maxGoodness = calculateGoodness(root, 0);
        cout << maxGoodness << "\n";

        // Clean up memory
        delete root;
    }

    return 0;
}
