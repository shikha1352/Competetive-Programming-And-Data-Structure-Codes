#include<bits/stdc++.h>
using namespace std;
int printS(int ind,vector<int>&ds,int s,int sum,int a[],int n){
    if(ind==3){
        if(s==sum){
            for(auto it:ds)
            cout<<it<<" ";
            cout<<endl;
            return 1;

        }
        return 0;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    int l=printS(ind+1,ds,s,sum,a,n);
    ds.pop_back();
    s-=a[ind];
    int r=printS(ind+1,ds,s,sum,a,n);
    return l+r;
}
int main(){
    int a[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    cout<<"subsequences are:"<<endl;
   cout<<"count is:"<<printS(0,ds,0,sum,a,n)<<endl;
}