#include<bits/stdc++.h>
using namespace std;
#define ll long long
int const mod=1000000007;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        ll x1,y1;
        cin>>x1>>y1;
        ll x2,y2;
        cin>>x2>>y2;
        
        if((x1<y1 && x2<y2 ) || (x1>y1 && x2>y2)){
            cout<<"yes"<<endl;
        }
        else{
            cout<<"no"<<endl;
        }
        
    }
}