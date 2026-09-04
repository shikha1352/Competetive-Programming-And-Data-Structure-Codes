#include<bits/stdc++.h>
using namespace std;
const int ALPHABET_SIZE=26;
struct trieNode{
    bool isEndOfWord;
    trieNode *children[ALPHABET_SIZE];
};

struct trieNode *getNode(){
    struct trieNode *pNode=new trieNode;

    pNode->isEndOfWord=false;
    for(int i=0;i<ALPHABET_SIZE;i++){
        pNode->children[i]=NULL;
    }
    return pNode;

}

void insert(trieNode *root,string key){
    struct trieNode *pCrawl=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!pCrawl->children[index]){
            pCrawl->children[index]=getNode();
        }
        pCrawl=pCrawl->children[index];
    }
    pCrawl->isEndOfWord=true; 
}

bool search(trieNode *root,string key){
    struct trieNode *pCrawl=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!pCrawl->children[index]){
            return false;
        }
        pCrawl=pCrawl->children[index];
    }
    return(pCrawl->isEndOfWord);
}
int main(){
    string keys[]={"the", "a", "there",
					"answer", "any", "by",
					"bye", "their"};

    int n=sizeof(keys)/sizeof(keys[0]);

    struct trieNode *root=getNode();
    for(int i=0;i<n;i++){
        insert(root,keys[i]);
    }

    cout<<"the"<<search(root,"the")<<endl;
    return 0;
}