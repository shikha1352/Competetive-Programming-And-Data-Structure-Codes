#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    ll t;
    cin>>t;
    while(t--){
        ll n ,f,a,b;
        cin>>n>>f>>a>>b;
        ll arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        if(arr[0]*a>=b){
            f=f-b;
        }
        else if(arr[0]*a<b){
            f=f-arr[0]*a;
        }
        for(int i=1;i<n;i++){
            ll d=arr[i]-arr[i-1];
            if(d*a>=b){
                f=f-b;
            }
            else if(d*a<b){
                f=f-d*a;
            }
        }
        if(f>0){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }

     }
}