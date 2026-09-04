#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    string s;
    cin>>s;
    int len=s.size();
    vector<int>v;
    int cnt=0;
    for(int i=len-1;i>=0;i--){
        if(cnt<6 && s[i]=='0'){
            v.push_back(0);
            cnt++;
        }
        else if(cnt==6){
            if(s[i]=='1'){
                v.push_back(1);
            }
        }
    }
    if(v.size()>=7){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}