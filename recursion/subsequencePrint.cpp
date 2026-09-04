#include<bits/stdc++.h>
using namespace std;
void printF(int ind, vector<int>&ds,int a[],int n){
    if(ind>=3){
        for(auto it:ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<<endl;
        return;

    }
    printF(ind+1,ds,a,n);
    ds.push_back(a[ind]);
    printF(ind+1,ds,a,n);
    ds.pop_back();
    

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int a[]={3,1,2};
    int n=3;
    vector<int>ds;
    printF(0,ds,a,n);
}