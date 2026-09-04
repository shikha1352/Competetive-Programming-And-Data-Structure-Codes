#include<bits/stdc++.h>
using namespace std;
#define ll long long
signed main(){
    int t;
    cin>>t;
    while(t--){
        int n,x,y;
        cin>>n>>x>>y;
        if((x>0 && y>0) || (x==0 && y==0)){
            cout<<"-1"<<endl;
            continue;
        }
        if(x==0){
            swap(x,y);

        }
        if(x==1){
            cout<<"1 ";
            for(int i=2;i<=n-1;i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            continue;
        }
        if((n-1)%x!=0){
            cout<<"-1"<<endl;
            continue;
        }
        ll p1=1,p2=2,win=0;
        for(int i=1;i<=n-1;i++){
            cout<<p1<<" ";
            win++;
            if(win==x){
                if(i==n-1){
                    break;
                }
                
                cout<<p2+1<<" ";
                p1=p2+1;
                p2=p1+1;
                win=1;
                i++;
                continue;
            }
            p2++;
        }
        cout<<endl;
    }
}