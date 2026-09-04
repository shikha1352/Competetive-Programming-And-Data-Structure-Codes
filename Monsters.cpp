#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        vector<int>ans;
        vector<pair<int,int>>p;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]%k==0){
                ans.push_back(i+1);
            }
            else
            p.push_back({v[i]%k,i+1});
        }
        sort(p.begin(),p.end(),[&](pair<int,int>x,pair<int,int>y){
            if(x.first==y.first){
                return (x.second<y.second);
            }
            else 
            return (x.first>y.first);
        });
        for(auto it:p){
            ans.push_back(it.second);
        }
        for(auto it:ans){
            cout<<it<<" ";
        }
        cout<<endl;
    }
}