#include<bits/stdc++.h>
using namespace std;
void solve(){
    string s1;
    cin>>s1;
    map<char,int>mp;
    for(auto it:s1){
        mp[it]++;
    }
    int cnt=0;
    for(auto it:mp){
        if(it.second%2==1){
            cnt++;
            if(cnt>1){
                cout<<"NO SOLUTION"<<endl;
                return;
            }
        }
    }
    string x="#";
    string ans="";
    for(auto it:mp){
        for(int i=0;i<it.second/2;i++){
            ans.push_back(it.first);
        }
        if(it.second%2!=0){
            x=it.first;
        }
    }
    string s=ans;
    if(x!="#"){
        s+=x;
    }
   reverse(ans.begin(),ans.end());
   s+=ans;
   cout<<s<<endl;
}
int main(){
    solve();
}