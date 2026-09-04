#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *links[26];
    int cntEndWith=0;
    int cntPrefix=0;
    bool containsKey(char ch){
        return(links[ch-'a']!=NULL);
    }
    Node *get(char ch){
        return (links[ch-'a']);
    }
    void put(char ch,Node *node){
        links[ch-'a']=node;

    }
    void increaseEnd(){
        cntEndWith++;
    }
    void increasePrefix(){
        cntPrefix++;
    }
};
int main(){

}