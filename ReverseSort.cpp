#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        string s1=s;
        sort(s.begin(),s.end());
        vector<int>v;
        for(int i=0;i<n;i++){
            if(s[i]!=s1[i]){
                v.push_back(i+1);
            }
        }
        if(v.size()==0){
            cout<<0<<endl;
        }
        else{
            cout<<1<<endl;
            cout<<v.size()<<" ";
            for(int i:v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }
}