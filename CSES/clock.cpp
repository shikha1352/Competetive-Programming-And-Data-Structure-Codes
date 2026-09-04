#include<bits/stdc++.h>
using namespace std;
int main(){

    int t;
    cin>>t;
    while(t--){
        int cnt=0;
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(a>b){
            int t=a;
            a=b;
            b=t;
        }
        for(int i=a;i<b;i++){
            if(i==c || i==d){
                cnt++;
            }
        }

        if(cnt==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}