#include<bits/stdc++.h>
using namespace std;
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
        int nonzero=0;
        int zero=0;
        for(int i=0;i<n;i++){
            if(v[i]==0){
                zero++;
            }
            else{
                nonzero++;
            }

        }
        if(zero==0){
            cout<<0<<endl;
        }
        else if(nonzero>=zero-1){
            cout<<0<<endl;
        }
        else{
            int mx=*max_element(v.begin(),v.end());
            if(mx==1){
                cout<<2<<endl;
            }
            else{
                cout<<1<<endl;
            }
        }
    }
}
        