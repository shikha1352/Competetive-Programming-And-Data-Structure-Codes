#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        set<char>st;
        int ans=0;
        for(auto it:s){
            st.insert(it);
            ans+=st.size();
        }
        cout<<ans<<endl;
    }
}
