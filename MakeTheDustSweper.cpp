#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        reverse(v.begin(),v.end());
        while(!v.empty() && v.back()==0)
        v.pop_back();
        if(v.empty()){
            cout<<0<<endl;
        }
        else{
            reverse(v.begin(),v.end());
            int ans=0;
            for(int i=0;i<v.size()-1;i++){
                if(v[i]==0){
                    ans+=1;
                }
                else{
                    ans+=v[i];
                }
            }
            cout<<ans<<endl;
        }
    }
}