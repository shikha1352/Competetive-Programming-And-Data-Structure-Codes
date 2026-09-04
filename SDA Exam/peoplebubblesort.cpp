#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,p=0;
    cout<<"Enter size"<<":";
    cin>>n;
    char s[n+1];
    cout<<"Enter string"<<":";
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<n-1;i++)
    {
        int flag=0;
        p++;
        cout<<"The string after pass"<<":"<<p<<endl;
        for(int j=0;j<n-1-i;j++)
        {
            if(s[j]>s[j+1])
            {
                swap(s[j],s[j+1]);
                flag=1;
            }
            for(int k=0;k<n;k++)
            {
                cout<<s[k]<<" ";
            }
            cout<<endl;
        }
        if(flag==0)
        {
            break;
        }
    }
    cout<<"The sorted string is"<<":"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<s[i]<<" ";
    }
    cout<<endl;
    return 0;

}

