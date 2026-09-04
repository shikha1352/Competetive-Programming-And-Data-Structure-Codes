#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int sz;
        cin>>sz;
        string s;
        cin>>s;
        set<char>p(s.begin(),s.end());
        vector<char>v(p.begin(),p.end());
        vector<pair<char,char>>x;
        int n=v.size();
        for(int i=0;i<n/2;i++){
             x.push_back({v[i], v[n - 1 - i]});
             x.push_back({v[n - 1 - i],v[i]});
        }
         if (n % 2 != 0) {
            x.push_back({v[n / 2], v[n / 2]});
        }
        string y;
        for(int i=0;i<s.size();i++){
            for(int j=0;j<x.size();j++){
                if(s[i]==x[j].first){
                    y+=x[j].second;
                }
            }
        }
        cout<<y<<endl;
    }
}