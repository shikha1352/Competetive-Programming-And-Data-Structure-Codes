#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* links[26];
    int cntEndWith=0;
    int cntPrefix=0;

    bool containsKey(char ch){
        return (links[ch-'a']!=NULL);
    }

    Node* get(char ch){
        return(links[ch-'a']);
    }
    void put(char ch,Node* node){
        links[ch-'a']=node;
    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
    void deletePrefix(){
        cntPrefix--;
    }
    void deleteEnd(){
        cntEndWith--;
    }
    int getEnd(){
        return cntEndWith;
    }
    int getPrefix(){
        return cntPrefix;
    }

};
void insert(string word,Node* root){
    Node* node=root;
    for(int i=0;i<word.size();i++){
        if(!node->containsKey(word[i])){
            node->put(word[i],new Node());
        }
        node=node->get(word[i]);
        node->increasePrefix();
    }
    node->increaseEnd();
}
int countWordEndWith(string word,Node* root){
    Node* node=root;
    for(int i=0;i<word.size();i++){
        if(node->containsKey(word[i])){
            node=node->get(word[i]);
        }
        else 
        return 0;
    }
    return node->getEnd();
}
int cntWordStartWith(string word,Node* root){
    Node* node=root;
    for(int i=0;i<word.size();i++){
        if(node->containsKey(word[i])){
            node=node->get(word[i]);
        }
        else return 0;
    }
    return node->getPrefix();
}
void reduce(string word,Node* root){
    Node* node=root;
    for(int i=0;i<word.size();i++){
        if(node->containsKey(word[i])){
            node=node->get(word[i]);
            node->deletePrefix();
        }
    }
    node->deleteEnd();

}
int main(){
    Node* root=new Node();
    int n;
    cin>>n;
    while(n--){
        int t;
        cout<<"Enter 1 for insert\nEnter 2 for reduce\n Enter 3 for CountwordENdWith\n enter 4 for cntWordStartWith"<<endl;
        cin>>t;
        if(t==1){
            string s;
        cin>>s;
        insert(s,root);
        }
        if(t==2){
            string s;
            cin>>s;
            reduce(s,root);
        }
        if(t==3){
            string s;
        cin>>s;
        cout<<countWordEndWith(s,root)<<endl;
        }
        if(t==4){
            string s;
        cin>>s;
        cout<<cntWordStartWith(s,root)<<endl;
        }
    }
   
   
}