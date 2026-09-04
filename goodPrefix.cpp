#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int>v(n);
        v[0]=a[0];
        for(int i=1;i<n;i++){
            v[i]=a[i]+v[i-1];
        }
        if(n==1){
            if(a[0]==0){
                cout<<"1"<<endl;
            }
            else{
                cout<<"0"<<endl;
            }
        }
        else{
            int ans=0;
            for(int i=1;i<n;i++){
                int m=v[i]-v[i-1];
                if(m==v[i-1]){
                    ans++;
                }
            }
            if(v[0]==0){
                ans++;
            }
            cout<<ans<<endl;
        }
    }
}