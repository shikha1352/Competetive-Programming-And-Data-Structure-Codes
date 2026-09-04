#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int c1 = 0, c0 = 0;
        int len = s.size();
        if (len == 1)
        {
            if (s[0] == '1')
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if(s[0]=='1' && s[1]=='1'){
            cout<<"YES"<<endl;
        }
        else
        {
            int c1 = count(s.begin(), s.end(), '1');
            int c0 = count(s.begin(), s.end(), '0');
            if (c1 == 1)
            {
                cout << "NO" << endl;
            }
            else if (s[0] == '1' && s[len - 1] == '1')
                cout << "YES" << endl;
            else if (s[0] == '1' || s[len - 1] == '1')
            {
                int c = 0;
                for (int i = 1; i < len - 1; i++)
                {
                    if (s[i] == '1' && s[i + 1] == '1')
                    {
                        cout << "YES" << endl;
                        c = 1;
                        break;
                    }
                   
                }
                if (c == 0)
                {
                    cout << "NO" << endl;
                }
            }
            else
            {
                cout << "No" << endl;
            }
        }
    }
    return 0;
}
