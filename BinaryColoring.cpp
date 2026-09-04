#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        cin >> x;
        vector<int> v;
        while (x)
        {
            if (x & 1)
            {
                v.push_back(1);
            }
            else
            {
                v.push_back(0);
            }
            x >>= 1;
        }
        v.push_back(0);

        for (int i = 0; i < v.size() - 1; i++)
        {
            if (v[i] == 1 && v[i + 1] == 1)
            {
                for (int j = i; j < v.size(); j++)
                {
                    if (v[j] == 0)
                    {
                        v[j] = 1;
                        v[i] = -1;
                        break;
                    }
                    else
                    {
                        v[j] = 0;
                    }
                }
            }
        }
        cout << v.size() << endl;
        for (auto it : v)
        {
            cout << it << " ";
        }
        cout << endl;
    }
}