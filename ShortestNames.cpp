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
    int ans=0;
    for (int i = 0; i < key.length(); i++) {
        int index = key[i] - 'a';
        if (pCrawl->cntPrefix==1) {
            break;
        }
        ans++;
        pCrawl = pCrawl->children[index];
    }
    return (ans);
}

int main() {
    
   int t;
   cin>>t;
   while(t--){
    Node* root = getNode();
    int n;
    cin>>n;
    vector<string>v(n);
    while(n--){
        string key;
        cin>>key;
        v.push_back(key);
        insert(root,key);
    }
    int d=0;
    for(int i=0;i<v.size();i++){
        d+=startWith(root,v[i]);
    }
    cout<<d<<endl;
   }
}
