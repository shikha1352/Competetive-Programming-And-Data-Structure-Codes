#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        ll flag = 0;
        ll n=s1.size();
        if (n == 1)
        {
            swap(s1, s2);
            cout << s1 << endl
                 << s2 << endl;
        }
        else
        {
           

            for (ll i = 0; i < n; i++)
            {
                

                if(i==0 && s1[0]>s2[0]){
                    flag=1;
                    i++;
                }
                ll x=s1[i]-'0';
                ll y=s2[i]-'0';
                if (flag == 0)
                {
                    if (x < y)
                    {
                        swap(s1[i], s2[i]);
                        flag = 1;
                    }
                }
                else if(flag==1)
                {
                    if (x > y)
                    {
                        swap(s1[i], s2[i]);
                    }
                }
                if(x==y)
                continue;
            }
            cout << s1 << endl
                 << s2 << endl;
        }
    }
}