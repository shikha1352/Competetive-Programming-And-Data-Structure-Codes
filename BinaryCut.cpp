#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int cnt1=0;
        int f1=0,f2=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0' &&f1==0){
                cnt1++;
                f1=1;
                f2=0;
            }
            else if(s[i]=='1' && f2==0){
                cnt1++;
                f2=1;
                f1=0;
            }
        }
        if(cnt1==1){
            cout<<"1"<<endl;
        }
        else if(cnt1==2 && s[0]=='1')
        cout<<"2"<<endl;
        else
        cout<<cnt1-1<<endl;
    }
}