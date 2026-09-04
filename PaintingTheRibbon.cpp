#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        if (n == 1 || m == 1)
        {
            cout << "NO" << endl;
        }
        else
        {
            float a = (float)n / m;
            int b = ceil(a);
            if ((n - b) <= k)
            {
                cout << "NO" << endl;
            }
            else
                cout << "YES" << endl;
        }
    }
}
