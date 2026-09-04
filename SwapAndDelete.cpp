#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        string a;
        cin >> a;
        ll c = 0;
        ll d = 0;
        
            for (ll i = 0; i < a.size(); i++)
            {
                if (a[i] == '0')
                {
                    c++;
                }
                else
                {
                    d++;
                }
            }
            for(int i=0;i<a.size();i++){
                if(a[i]=='1')
                {
                    if(c>0){
                        c--;
                    }
                    else {
                        break;
                    }
                }
                else{
                    if(d>0){
                        d--;
                    }
                    else {
                        break;
                    }
                }

            }
            cout<<c+d<<endl;
    }
}