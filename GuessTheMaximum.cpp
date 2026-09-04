#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];

        }
        vector<int>ok;
        for(int i=0;i<n-1;i++){
            int x=max(a[i],a[i+1]);
            ok.push_back(x);
        }
        sort(ok.begin(),ok.end());
        cout<<ok[0]-1<<endl;
    }
}