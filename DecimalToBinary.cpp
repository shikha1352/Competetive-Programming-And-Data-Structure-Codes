#include<bits/stdc++.h>
using namespace std;
void solve(int n){
    string res="";
    while(n>1){
        if(n%2==1){
            res+='1';
        }
        else
        res+='0'; 

        n/=2;
    }
    cout<<res<<endl;
}
signed main(){
    int n;
    cin>>n;
    solve(n);
}