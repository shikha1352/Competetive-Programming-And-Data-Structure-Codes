#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int h){
    int i=l,j=mid+1,k=0;
    int b[h-l+1];
    while(i<=mid && j<=h){
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else{
            b[k]=a[j];
            j++;
        }
        k++;
    }
        while(j<=h){
            b[k]=a[j];
            j++;
            k++;
        }
    
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
        for(int i=0,j=l;i<(h-l+1);i++,j++){
        a[j]=b[i];
    }
}


void mergesort(int a[],int l,int h){
    if(l<h){
        int mid=(l+h)/2;
        mergesort(a,l,mid);
        mergesort(a,mid+1,h);
        merge(a,l,mid,h);
    }
    else return;
}
int main(){
    int n;
    cout<<"Enter the size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter the array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int l=0;
    int h=n-1;
    mergesort(a,l,h);
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

} 