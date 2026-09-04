#include<bits/stdc++.h>
using namespace std;
int partition(int a[],int l,int h)
{
    int pivot=a[l];
    int i=l;
    int j=h;
    while(i<j)
    {
        while(a[i]<=pivot)
        {
            i++;
        }
        while(a[j]>pivot)
        {
            j--;
        }
        if(i<j)
        {
            swap(a[i],a[j]);
        }
    }
    swap(a[l],a[j]);
    return j;
}
int quicksort(int a[],int l,int h)
    {
        if(l<h)
        {
            int j=partition(a,l,h);
            quicksort(a,l,j-1);
            quicksort(a,j+1,h);
        }
    }

int main()
{
    int n;
    cout<<"Enter size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int l=0,h=n-1;
    quicksort(a,l,h);
    cout<<"The array after quicksort:"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
