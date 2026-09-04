#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int ar[n];
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        sort(ar,ar+n);
        float x = static_cast<float>(n) / 2.0;
        int up=ceil(x);
        //cout<<up<<endl;
        int cnt=1;
        for(int i=up;i<n;i++){
            if(ar[up-1]>=ar[i])
            {
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}