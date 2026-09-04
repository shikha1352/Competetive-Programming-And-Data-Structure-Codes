#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main() {
    int t;
    cin >> t;
    while (t--) {
       ll n;
       cin>>n;
       vector<int>a(n);
       
       for(int i=0;i<n;i++){
        cin>>a[i];
       }
       bool flag=0;
       int pos=0;
       for(int i=0;i<n;i++){
        if(a[i]==1){
            flag=1;
            pos=i;
            break;
        }
        }
        if(flag==0){
            cout<<0<<endl;
            continue;
        }
        int res=0;
        int box=0,filled=0;
        for(int i=pos+1;i<n;i++){
            if(a[i]==1){
                box++;
            }
            else{
                filled+=box/2;
                
                box=box%2;
            }
            res=max(box+filled,res);
            
       }
       cout<<res+1<<endl;
       
    }
    return 0;
}
