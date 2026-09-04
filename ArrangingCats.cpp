#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long n,c=0,d=0;
        cin>>n;
       string s,f;
       cin>>s>>f;
       for(long long i=0;i<n;i++){
            if(f[i]=='0' && s[i]=='1'){
                c++;
            }
            else if(f[i]=='1' && s[i]=='0'){
                d++;
            }
       }
       if(c>d){
       cout<<c<<endl;
       }
       else{
        cout<<d<<endl;
       }
    }

}