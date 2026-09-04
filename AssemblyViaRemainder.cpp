#include<bits/stdc++.h>
using namespace std;
const int m=1000000000;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int x[n-1];
        for(int i=0;i<n-1;i++){
            cin>>x[i];
        }
        int a[n];
        a[n-1]=m;
        for(int i=n-2;i>=0;i--){
            a[i]=a[i+1]-x[i];
        }
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }

}