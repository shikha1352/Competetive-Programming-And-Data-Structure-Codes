#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        int ans=0;
        for(char c='a';c<='z';c++){
            int mn=min(mp[c],mp[c-32]);
            ans+=mn;
            mp[c]-=mn;
            mp[c-32]-=mn;
        }
        for(char c='a';c<='z';c++){
            int sum=max(mp[c],mp[c-32]);
            int mn=min(k,sum/2);
            ans+=mn;
            k-=mn;
        }
        cout<<ans<<endl;
    }
}