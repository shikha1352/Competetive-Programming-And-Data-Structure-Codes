#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n+1];
        map<int,int>m;
        for(int i=0;i<n;i++){
            cin>>arr[i];
            m[arr[i]]++;
        }
        if(n==1){
            cout<<"-1"<<endl;
        }
        else if(m.size()==1){
            cout<<"-1"<<endl;
        }
        else{
            int ans=n;
            int j=0;
            for(int i=0;i<n;i++){
                if(arr[i]==arr[0])
                j+=1;
                else{
                ans=min(ans,j);
                j=0;
                }
            }
            ans=min(ans,j);
            cout<<ans<<endl;
        }
    }
}