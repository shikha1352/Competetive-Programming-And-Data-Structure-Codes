#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,sum=0;
        cin>>n;
        vector<ll>v(n);
        set<ll>st;
        st.insert(0);
        int flag=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(i%2==0){
                v[i]*=-1;
            }
            sum+=v[i];
            if(st.find(sum)!=st.end()){
                flag=1;
            }
            st.insert(sum);
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}