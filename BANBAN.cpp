#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>p;
        
          for(int i=0;i<3*n;i+=3){
            if(i+1>=(3*n-i))
            break;
            p.push_back({(i+1),(3*n-i)});
            
        }
        cout<<p.size()<<endl;
        for(int i=0;i<p.size();i++){
            int it1=p[i].first;
            int it2=p[i].second;
            cout<<it1<<" "<<it2<<endl;
        }
        
    }
}