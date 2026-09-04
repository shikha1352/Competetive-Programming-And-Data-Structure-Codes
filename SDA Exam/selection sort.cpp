#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p=0;
    cout<<"Enter size of the array:"<<endl;
    cin>>n;
    int a[n];
    cout<<"enter the elements f the array:"<<endl;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n-1; i++)
    {
        int min=i;
        p++;
        cout<<"The array after pass:"<<p<<endl;
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        if(min!=i)
        {
            swap(a[i],a[min]);
        }
        for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
    }
    cout<<"The array after selection sort:"<<endl;
    for(int i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

