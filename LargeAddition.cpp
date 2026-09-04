#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int len=s.size();
        if(s[0]!='1' || s[len-1]=='9'){
            cout<<"NO"<<endl;
        }
        else{
            bool flag=0;
            for(int i=0;i<len-1;i++){
                if(s[i]=='0'){
                    flag=1;
                    break;
                }
            }
            if(flag){
                cout<<"NO"<<endl;

            }
            else{
                cout<<"YES"<<endl;
            }
        }
    }
}