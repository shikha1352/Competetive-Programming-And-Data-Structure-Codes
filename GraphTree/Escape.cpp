#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll>v(n);
        for (int  i = 0; i < n; i++){
            cin>>v[i];
        }
        vector<ll>left(n);
        left[0]=0;
        left[1]=1;
        for(int i=2;i<n;i++){
            if((v[i]-v[i-1])<(v[i-1]-v[i-2]))
            left[i]=left[i-1]+1;
            else
            {
                left[i]=left[i-1]+(v[i]-v[i-1]);
            }
        }
        vector<ll>right(n);
        right[n-1]=0;
        right[n-2]=1;
        for(int i=n-3;i>=0;i--){
            if((v[i+1]-v[i])<(v[i+2]-v[i+1]))
            right[i]=right[i+1]+1;
            else
            {
                right[i]=right[i+1]+(v[i+1]-v[i]);
            }
        }
        ll m;
        cin>>m;
        while(m--){
            ll a,b;
            cin>>a>>b;
            a=a-1;
            b=b-1;
            if(a<b){
                cout<<left[b]-left[a]<<endl;
            }
            else{
                cout<<right[b]-right[a]<<endl;
            }

        }
        
    }
}