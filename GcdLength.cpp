#include<bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        ll x=pow(10,c-1);
        ll y=pow(10,c-1);
        while(x<(ll)pow(10,a-1)){
          x*=2;
        }
         while(y<(ll)pow(10,b-1)){
           y*=3;
        }
        cout<<x<<" "<<y<<endl;
        
    }
}