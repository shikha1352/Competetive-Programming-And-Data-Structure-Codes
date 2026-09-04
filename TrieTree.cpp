#include<bits/stdc++.h>
using namespace std;
struct trienode{
    bool isEndOfWord;
    trienode *child[26];
};
struct trienode *getnode(){
    struct trienode *root=new trienode;
    root->isEndOfWord=false;
    for(int i=0;i<26;i++){
        root->child[i]=NULL;
    }
    return root;

}
void insert(trienode *root,string key){
    struct trienode *crawl=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!crawl->child[index]){
            crawl->child[index]=getnode();
        }
        crawl=crawl->child[index];
    }

    crawl->isEndOfWord=true;
}
bool search(trienode *root,string key){
    struct trienode *crawl=root;
    for(int i=0;i<key.length();i++){
        int index=key[i]-'a';
        if(!crawl->child[index]){
            return false;
        }
        crawl=crawl->child[index];
    }
    return(crawl->isEndOfWord);
}
int main(){
    string keys[]={"the", "a", "there",
					"answer", "any", "by",
					"bye", "their"};
    int n=sizeof(keys)/sizeof(keys[0]);
    struct trienode *root=getnode();
    for(int i=0;i<n;i++){
        insert(root,keys[i]);
    }
    cout<<"the->"<<search(root,"the")<<endl;
    cout<<"good->"<<search(root,"good")<<endl;
    return 0;
}
