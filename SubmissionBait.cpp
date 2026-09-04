#include<bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
            mp[a[i]]++;
        }
        bool flag=0;
        sort(a.begin(),a.end());
        for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second%2==1){
                    cout<<"YES"<<endl;
                    flag=1;
                    break;
                }
        }
        if(flag==0){
            cout<<"NO"<<endl;
        }
    }
}