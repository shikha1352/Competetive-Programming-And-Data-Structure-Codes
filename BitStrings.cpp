#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+7;
int main(){
    int n,ans=1;
    cin>>n;
    for(int i=1;i<=n;i++){
        ans*=2;
        ans%=INF;
    }
    cout<<ans;
}