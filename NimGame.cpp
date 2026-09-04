#include<bits/stdc++.h>
using namespace std;
int numberCount(vector<int>&piles){
    int nim_sum=0;
    int count=0;
    for(int pile:piles){
        nim_sum=nim_sum^pile;
    }
    for(int pile:piles){
        int new_nim_sum=0;
        new_nim_sum=nim_sum^pile;
        if(new_nim_sum<pile)
        count++;
    }
    return count;
}
int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>piles;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            piles.push_back(x);
        }
        int result=numberCount(piles);
        cout<<"Case "<<cs++<<": "<<result<<endl;
    }
}