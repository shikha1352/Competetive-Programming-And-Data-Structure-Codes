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
        sort(a.begin(),a.end());
        vector<int>v;
        for(int i=0;i<n;i++){
            if(a[i]%a[0]!=0){
                v.push_back(a[i]);
            }
        }
        bool flag=1;
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            if(v[i]%v[0]!=0){
                flag=0;
                break;
            }
        }
        if(flag){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }
}