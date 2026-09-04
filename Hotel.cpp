#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;
const int mx=200001;
int a[mx];
int st[4*mx];
int n,m;
void build(int si,int ss,int se){
    if(ss==se){
        st[si]=a[ss];
        return;
    }
    int mid=(ss+se)/2;
    build(si*2,ss,mid);
    build(si*2+1,mid+1,se);
    st[si]=max(st[2*si],st[2*si+1]);
}
int querry(int si,int ss,int se,int val){
    if(ss==se){
        return ss;
    }
    else{
        int mid=(ss+se)/2;
    if(st[si*2]>=val){
        return querry(2*si,ss,mid,val);
    }
    else{
        return querry(2*si+1,mid+1,se,val);
    }
    }
    
}
void update(int si,int ss,int se,int index){
    if(ss==se){
        st[si]=a[index];
        return;
    }
    int mid=(ss+se)/2;
    if(index<=mid){
        update(2*si,ss,mid,index);
    }
    else{
        update(2*si+1,mid+1,se,index);
    }
    st[si]=max(st[si*2],st[si*2+1]);
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    build(1,1,n);
    for(int i=1;i<=m;i++){
        int x;
        cin>>x;
        if(st[1]<x){
            cout<<0<<endl;
        }
        else{
            int s=querry(1,1,n,x);
        cout<<s<<endl;
        a[s]=a[s]-x;
        update(1,1,n,s);
        }
        
    }
}
int32_t main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    // int t;
    // cin >> t;
    // while (t--) {
        solve();
    //}
    return 0;
}
