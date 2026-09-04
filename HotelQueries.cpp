#include<bits/stdc++.h>
using namespace std;
#define ll long long
int st[8000001];
int a[200000];
int b[200000];
void buildTree(ll si,ll ss,ll se){
    if(ss==se){
        st[si]=a[ss];
        return;
    }
    ll mid=(ss+se)/2;
    buildTree(2*si+1,ss,mid);
    buildTree(2*si+2,mid+1,se);
    st[si]=max(st[2*si+1],st[2*si+2]);
}
ll find(ll si,ll ss,ll se,ll m){
    if(ss==se){
        return ss;
    }
    else{
        ll mid=(ss+se)/2;
        if(st[2*si+1]>=m){
            return find(2*si+1,ss,mid,m);
        }
        else{
            return find(2*si+2,mid+1,se,m);
        }

    }
}
void update(ll si,ll ss,ll se,ll index){
    if(ss==se){
        st[si]=a[index];
        return;
    }
    ll mid=(ss+se)/2;
    if(index<=mid){
        update(2*si+1,ss,mid,index);
    }
    else{
        update(2*si+2,mid+1,se,index);
    }
    st[si]=max(st[2*si+1],st[2*si+2]);

}
int main(){
    ll n,m;
    cin>>n>>m;
   
    for(ll i=0;i<n;i++){
        cin>>a[i];
    }
    for(ll j=0;j<m;j++){
        cin>>b[j];
    }

    buildTree(0,0,n-1);
    for(ll i=0;i<m;i++){
        ll m=b[i];
        if(st[0]<m){
            cout<<"0"<<" ";
        }
        else{
            ll index=find(0,0,n-1,m);
            cout<<index+1<<" ";
            a[index]-=m;
            update(0,0,n-1,index);

        }
    }

}