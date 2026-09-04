#include<bits/stdc++.h>
using namespace std;
int main(){
    map<int,string>m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        int x;
        string s;
        cin>>x>>s;
        m.insert({x,s});
    }
    for(auto pr:m){
        cout<<pr.first<<" "<<pr.second<<endl;
    }
}
