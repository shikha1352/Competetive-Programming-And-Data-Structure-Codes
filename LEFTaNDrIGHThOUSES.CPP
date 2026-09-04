#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>prefix(n+1);
        prefix[0]=0;
        for(int i=0;i<n;i++){
            prefix[i+1]=prefix[i]+s[i]-'0';
        }
        int ans=-1;
        for(int i=0;i<=n;i++){
            int left=i-prefix[i];
            int right=prefix[n]-prefix[i];
            if(2*left>=i && (n-i)<=2*right){
                if(ans==-1 || abs(n-2*i)<abs(n-2*ans)){
                    ans=i;
                }
            }
        }
        cout<<ans<<endl;

    }

}