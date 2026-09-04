#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string p,q,r;
        cin>>p>>q>>r;
        int count=0;
        for(int i=0;i<n;i++){
            if(p[i]!=r[i] && q[i]!=r[i]){
                count=1;
                break;
            }
            
        }
        if(count==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
        
    }
}