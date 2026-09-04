#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int arr[N];
int gcd(int a,int b)
{
    int t;
    while(b){a=a%b;
    t=a;
    a=b;
    b=t;
    }
    return a;
}
struct segment{
    int gcd_;
    int cnt;
    segment(){
        gcd_=0;
        cnt=0;
    }
    segment(int val)
    {
        gcd_=val;
        cnt=1;
    }
    void add(segment left,segment right)
    {
        cnt=0;
       gcd_=gcd(left.gcd_,right.gcd_);
       if(gcd_==left.gcd_)
       {
           cnt+=left.cnt;
       }
       if(gcd_==right.gcd_)
       {
           cnt+=right.cnt;
       }
    }
}seg[4*N];
 
void build(int s,int e,int node)
{
    if(s>e)
    return;
    if(s == e)
    {
        seg[node]=segment(arr[s]);
        return;
    }
    int mid=s+e>>1;
    build(s,mid,2*node+1);
    build(mid+1,e,2*node+2);
    seg[node].add(seg[2*node+1],seg[2*node+2]);
}
 
segment query(int s,int e,int l,int h,int node)
{
    if(s>e||s>h||e<l)
    return segment();
    if(l<=s && e<=h)   
     return seg[node];      
     int mid=s+e>>1;
    segment temp=segment();
    temp.add(query(s,mid,l,h,2*node+1),query(mid+1,e,l,h,2*node+2));
    return temp;
 
}
 
int main() {
    int n;
    
    cin>>n;
    int i;
    
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
   
    build(0,n-1,0);
    int t,l,r;
   cin>>t;
    while(t--)
    {
        cin>>l>>r;
       cout << (r - l + 1) - query(0, n - 1, l - 1, r - 1, 0).cnt << endl;

    }
 
    return 0;
}