#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        vector<int>suf(n,0);
        suf[n-1]=1;
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+(a[i]==a[n-1]);
        }
        if(a[0]==a[n-1]){
            if(suf[0]%k==0 || suf[0]>=k){
                cout<<"YES"<<endl;
                continue;
            }
        }
        bool flag=0;
        int cnt=0;
        for(int i=0;i<n-1;i++){
            cnt+=(a[i]==a[0]);
            if(cnt%k==0 && suf[i+1]>=k){
                flag=1;
                break;
            }
        }
        if(flag){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}