#include<bits/stdc++.h>
using namespace std;
#define ll long long
int st[8000001];
int a[200000];

void buildTree(ll si,ll ss,ll se){
    if(ss==se){
        st[si]=a[ss];
        return;
    }
    ll mid=(ss+se)/2;
    buildTree(2*si+1,ss,mid);
    buildTree(2*si+2,mid+1,se);
    st[si]=(st[2*si+1]+st[2*si+2]);
}
ll querry(ll si,ll ss,ll se,ll qs,ll qe){
    if(ss>qe || se<qs){
        return 0;
    }
    if(ss>=qs && se<=qe){
        return st[si];
    }
    int mid=(ss+se)/2;
    return (querry(2*si+1,ss,mid,qs,qe)+querry(2*si+2,mid+1,se,qs,qe));
}
void update(ll si,ll ss,ll se,ll index, int val){
    if(ss==se){
        a[index] = val;
        st[si]= val;
        return;
    }
    ll mid=(ss+se)/2;
    if(index<=mid){
        update(2*si+1,ss,mid,index, val);
    }
    else{
        update(2*si+2,mid+1,se,index, val);
    }
    st[si]=(st[2*si+1]+ st[2*si+2]);
}
int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
         int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        buildTree(0,0,n-1);
        cout<<"Case "<<cs++<<":"<<endl;
        while(q--){
            int x;
            cin>>x;
            if(x==1){
                int y;
                cin>>y;
                cout<<a[y]<<endl;
                update(0,0,n-1,y, 0);
            }
            if(x==2){
                int y,z;
                cin>>y>>z;
                a[y]=a[y]+z;
                update(0,0,n-1,y, a[y]);
            }
            if(x==3){
                int y,z;
                cin>>y>>z;
                int q=querry(0,0,n-1,y,z);
                cout<<q<<endl;
            }
        }
        
    }
    return 0;
}
