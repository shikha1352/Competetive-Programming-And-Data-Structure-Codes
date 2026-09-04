#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 100001
int ar[N];
int st[4*N];
void build(int si,int ss,int se){
    if(ss==se){
        st[si]=ar[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(2*si+1,ss,mid);
    build(2*si+2,mid+1,se);
    st[si]=(st[2*si+1]+st[2*si+2]);
}
void update(int si,int ss,int se,int qi,int v){
    if(ss==se){
        ar[qi]=v;
        st[si]=v;
        return;
    }
    int mid=(ss+se)/2;
    if(qi<=mid){
        update(2*si+1,ss,mid,qi,v);
    }
    else{
        update(2*si+2,mid+1,se,qi,v);
    }
    st[si]=(st[2*si+1]+st[2*si+2]);
}
int query(int si,int ss,int se,int qs,int qe){
    if(ss>qe || se<qs){
        return 0;
    }
    if(ss>=qs && se<=qe){
        return st[si];
    }
    int mid=(ss+se)/2;
    return(query(2*si+1,ss,mid,qs,qe)+query(2*si+2,mid+1,se,qs,qe));
}
int32_t main(){
    int t,cs=1;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;
        for(int i=0;i<n;i++){
            cin>>ar[i];
        }
        build(0,0,n-1);
        cout<<"Case "<<cs++<<":"<<endl;
        while(q--){
            int ts;
            cin>>ts;
            if(ts==1){
                int v;
                cin>>v;
                cout<<ar[v]<<endl;
                update(0,0,n-1,v,0);
            }
            else if(ts==2){
                int x,y;
                cin>>x>>y;
                ar[x]=ar[x]+y;
                update(0,0,n-1,x,ar[x]);

            }
            else if(ts==3){
                int x,y;
                cin>>x>>y;
                int s=query(0,0,n-1,x,y);
                cout<<s<<endl;

            }
        }
    }

}