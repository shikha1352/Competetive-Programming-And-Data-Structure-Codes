#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s="abcdefghijklmnopqrstuvwxyz";
        string t[4];
        if(n<=27){
            t[0]=s[0];
            t[1]=s[0];
            t[2]=s[n-2-1];
        }
        else if(n<=53){
            t[0]=s[0];
            t[1]=s[n-27-1];
            t[2]=s[26-1];
        }
        else{
            t[0]=s[n-52-1];
            t[1]=s[26-1];
            t[2]=s[26-1];

        }

        for(int i=0;i<3;i++){
            cout<<t[i];
        }
        cout<<endl;
    }
 }