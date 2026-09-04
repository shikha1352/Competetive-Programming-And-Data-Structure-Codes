#include<bits/stdc++.h>
using namespace std;
int BinarySearch(int a[],int n,int data)
{
    int l=0,h=n-1;
    while(l<=h)
    {
        int mid=(l+h)/2;
        if(data==a[mid])
        {
            return mid;
            break;
        }
        else if(data<a[mid])
        {
            h=mid-1;
        }
        else if(data>a[mid])
        {
            l=mid+1;
        }
    }
}
int main()
{
    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int data;
    cout<<"Enter the data what you want to search:"<<endl;
    cin>>data;
    int position=BinarySearch(a,n,data);
    cout<<"The location of the data is:"<<position+1<<endl;
}
