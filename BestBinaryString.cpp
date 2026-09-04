#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int n=s.size();
        vector<char>ans;
        for(int i=0;i<n;i++){
            if(s[i]!='?'){
                 ans.push_back(s[i]);
            }
            else if(s[i]=='?'){
                if(ans.empty()){
                ans.push_back('0');
            }
                else{
                    ans.push_back(ans.back());
                }
            }
        }
        for(int i=0;i<n;i++){
            cout<<ans[i];
        }
        cout<<endl;
        
    }
}