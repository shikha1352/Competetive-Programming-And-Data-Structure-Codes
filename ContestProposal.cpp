#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        int j=0,cnt=0,flag=n;
        for(int i=0;i<n;i++){
            if(j>=flag){
                break;
            }
            else if(b[i]<a[j]){

                cnt++;
                flag--;
            }
            else{
                j++;
            }
        }
        cout<<cnt<<endl;
    }
}