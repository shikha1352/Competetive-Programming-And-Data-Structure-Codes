#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const mod=1000000007;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<int>v1;
        vector<int>v2;
        for(int i=1;i<=n;i++){
            
            v1.push_back(i);
        }
        for(int i=n;i>=1;i--){
            v2.push_back(i);
        }
        
        for(int i=0;i<n/2;i++){
            cout<<v1[i]<<" ";
            cout<<v2[i]<<" ";
        }
        if(n%2==0){
            cout<<endl;
        continue;
        }
        else{
        cout<<v1[n/2];
        }
        cout<<endl;
    }
}