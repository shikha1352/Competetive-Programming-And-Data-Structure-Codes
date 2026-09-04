#include<bits/stdc++.h>
using namespace std;
void printS(int ind,vector<int>&ds,int s,int sum,int a[],int n){
    if(ind==3){
        if(s==sum){
            for(auto it:ds)
            cout<<it<<" ";
            cout<<endl;
        }
        return;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    printS(ind+1,ds,s,sum,a,n);
    ds.pop_back();
    s-=a[ind];
    printS(ind+1,ds,s,sum,a,n);
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    printS(0,ds,0,sum,a,n);
}