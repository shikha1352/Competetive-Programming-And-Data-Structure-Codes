#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        map<char,int>mp;
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        int ans=0;
        if(mp.size()<7){
                int p=7-mp.size();
                ans=p*m;
            }
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second<m){
                ans+=(m-it->second);
            }
        }
        cout<<ans<<endl;
    }
}