#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<string>v;
    v.push_back("0");
    v.push_back("1");
    for(int i=2;i<=n;i++){
        int size=v.size();
        for(int j=size-1;j>=0;j--){
            v.push_back(v[j]);
        }
        for(int j=0;j<size;j++){
            v[j]="0"+v[j];
            v[j+size]="1"+v[j+size];
        }
    }
    for(string it:v)
        cout<<it<<endl;
}