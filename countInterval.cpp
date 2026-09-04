#include<bits/stdc++.h>
using namespace std;
const long long int m=1e18;
int main(){
int t;
cin>>t;
while(t--){
    int n;
    long long int l,r,cnt=0;
    long long int v[m]={0};
    cin>>n>>l>>r;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        for(int i=l;i*i<=r;i++){
            if(i==1){
                continue;
            }
            else if(i%x==0){
                while(i%x==0){
                    if(v[i]==0){
                        cnt++;
                        v[i]=1;
                    }
                    i+=i;
                }
            }
        }
    }
    cout<<cnt<<endl;
}
}
