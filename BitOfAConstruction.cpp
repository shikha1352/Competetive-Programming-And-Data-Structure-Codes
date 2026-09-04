#include<bits/stdc++.h>
using namespace std;
#define int long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int m=-1;
        int st=0;
        for(int i=0;i<=30;i++){
            if(k &(1<<i)){
                m=i;
                st++;
            }

        }
        if(n==1 || m+1==st){
            cout<<k<<" ";
            for(int i=1;i<n;i++){
                cout<<"0"<<" ";
            }
            cout<<endl;
        }
        else{
            int value=(1<<m)-1;
            int e=k-value;
            cout<<value<<" "<<e<<" ";
            for(int i=1;i<n-1;i++){
                cout<<"0"<<" ";
            }
            cout<<endl;
        }
    }
}