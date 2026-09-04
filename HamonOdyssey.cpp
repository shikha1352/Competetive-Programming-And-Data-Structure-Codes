#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        int ans,cnt=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        if(n==1){
            cout<<1<<endl;
            continue;
        }
        ans=v[0];
        for(int i=0;i<n;i++){
            ans &= v[i];
            if(ans==0){
                cnt++;
                ans=(i+1<n?v[i+1]:0);
            }
        }
        if(cnt==0){
            cnt=1;
        }
        cout<<cnt<<endl;
    }
}