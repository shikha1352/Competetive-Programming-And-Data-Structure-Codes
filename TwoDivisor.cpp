#include<bits/stdc++.h>
using namespace std;
#define ll long long
int GCD(ll a,ll b)
{
    if(b==0)
    {
        return a;
    }
    else
    {
        return GCD(b,a%b);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        ll a,b;
        cin>>a>>b;
        ll g=GCD(a,b);
        ll LCM=(a*b)/g;
        if(LCM==b)
        {
            cout<<(LCM*b)/a<<endl;
        }
        else
        {
            cout<<LCM<<endl;
        }
    }
}