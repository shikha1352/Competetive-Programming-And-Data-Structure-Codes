#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int zro=0,cnt=0,ans=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                while(s[i]=='0'){
                    zro++;
                    i++;
                }
            if(cnt>=1){
                ans+=zro*(cnt+1);
            }
            zro=0;
            }
             if(s[i]=='1'){
                cnt++;
            }
        }
        cout<<ans<<endl;
    }
}