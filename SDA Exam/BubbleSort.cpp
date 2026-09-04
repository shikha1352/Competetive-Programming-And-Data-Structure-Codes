#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int pass=0;
    for(int i=0;i<n-1;i++){
        pass++;
        int flag=0;
        cout<<"The pass number is:"<<pass<<endl;
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
                flag=1;
            }
            for(int k=0;k<n;k++){
                cout<<a[k]<<" ";
            }
            cout<<endl;
        }
        if(flag==0){
            break;
        }
    }
}