#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
    int a=0,b=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'){
            a+=1;
        }
        else{
            b+=1;
        }
    }
    cout<<abs(a-b)<<endl;
    }
}