//print n times using recursion
#include<bits/stdc++.h>
using namespace std;
void f(int i,int n)
{
    //base condition
    if(i>n)
    return;
    cout<<"raj"<<endl;
    f(i+1,n);
}
//print (1-n)
void food(int i,int n){
    if(i>n){
        return;
    }
    cout<<i<<endl;
    food(i+1,n);
}

    //print(n-1)
void yes(int i,int n){
    if(i<1)
    return;
     cout<<i<<endl;
    yes(i-1,n);
}
//backtrack (1-n)
void no(int i,int n){
    if(i<1)
    return;
    no(i-1,n);
    cout<<i<<" ";
}
//backtrack(n-1)
void nto1(int i,int n){
    if(i>n)return;
    nto1(i+1,n);
    cout<<i<<" ";
}
int main(){
    int n;
    cin>>n;
    //f(1,n);
    //food(1,n);
    //yes(n,n);
    //no(n,n);
    nto1(1,n);
}