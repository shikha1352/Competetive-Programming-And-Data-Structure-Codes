#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll c = 0, d = 0;
        for (ll i = 0; i < n; i++)
        {
            ll x;
            cin >> x;
            if (x == 0)
            {
                c++;
            }
            else if (x < 0)
            {
                d++;
            }
        }
        if (c > 0)
        {
            cout << "0" << endl;
        }
        else if (d > 0)
        {
            if (d % 2 == 1)
            {
                cout << "0" << endl;
            }
            else
            {
                cout << "1" << endl;
                cout << "1"
                     << " 0" << endl;
            }
        }
        else
        {
            cout << "1" << endl;
            cout << "1"
                 << " 0" << endl;
        }
    }
}