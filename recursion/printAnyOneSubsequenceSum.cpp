#include<bits/stdc++.h>
using namespace std;
bool printS(int ind,vector<int>&ds,int s,int sum,int a[],int n){
    if(ind==3){
        if(s==sum){
            for(auto it:ds)
            cout<<it<<" ";
            cout<<endl;
            return true;

        }
        return false;
    }
    ds.push_back(a[ind]);
    s+=a[ind];
    if(printS(ind+1,ds,s,sum,a,n)==true){
        return true;
    }
    ds.pop_back();
    s-=a[ind];
    if(printS(ind+1,ds,s,sum,a,n)==true){
        return true;
    }
    return false;
}
int main(){
    int a[]={1,2,1};
    int n=3;
    int sum=2;
    vector<int>ds;
    printS(0,ds,0,sum,a,n);
}