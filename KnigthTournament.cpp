#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;

    vector<int>a(n+1,0);
    set<int>s;
    for(int i=1;i<=n;i++){
        s.insert(i);
    }
    while(m--){
        int l,r,w;
        cin>>l>>r>>w;
        auto it=s.lower_bound(l);
       
        while(*it<=r  && it!=s.end()){
            if(*it!=w){
                a[*it]=w;
                auto x = it;
                it++;
                s.erase(x);
            }
            else{
                it++;
            }

        }

    }
    for(int i=1;i<=n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
} 