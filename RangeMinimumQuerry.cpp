#include<bits/stdc++.h>
using namespace std;
int arr[100001],st[400004];
void buildtree(int si,int ss,int se){
    if(ss==se){
        st[si]=arr[ss];
        return;
    }
    int mid=(ss+se)/2;
    buildtree(2*si,ss,mid);
    buildtree(2*si+1,mid+1,se);
    st[si]=min(st[2*si],st[2*si+1]);
}
int querry(int si,int ss,int se,int qs,int qe){
    if(ss>qe || se<qs){
        return INT_MAX;
    }
    if(ss>=qs && se<=qe){
        return st[si];
    }
    int mid=(ss+se)/2;
    return min(querry(2*si,ss,mid,qs,qe),querry(2*si+1,mid+1,se,qs,qe));
}
int main(){
    int n,q,l,r;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    buildtree(1,1,n);
    
    cin>>q;
    while(q--){
        
        cin>>l>>r;
        cout<<querry(1,1,n,l+1,r+1)<<endl;
    }

}