#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,i,flag=0;
    cout<<"Enter size:"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int data;
    cout<<"Enter data what u want to search:"<<endl;
    cin>>data;
    for(int i=0;i<n;i++)
    {
        if(a[i]==data)
        {
            cout<<"Data found at the location:"<<i+1<<endl;
            flag=1;
            break;
        }
    }
    if(flag==0)
    {
        cout<<"Data is not found"<<endl;
    }
}
