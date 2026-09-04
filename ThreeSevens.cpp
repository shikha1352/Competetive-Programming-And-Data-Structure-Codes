#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int m;
        cin >> m;
        int mx = 0;
        map<int, int> mp;
        for (int i = 1; i <= m; i++)
        {
            int n;
            cin >> n;
            vector<int> a(n);
            for (int j = 0; j < n; j++)
            {
                cin >> a[j];
                mp[a[j]] = i;
            }
        }
        vector<int> sum(m + 1, -1);

        for (auto it : mp)
        {
            if (sum[it.second] == -1)
            {
                sum[it.second] = it.first;
            }
        }
        bool flag=0;
        for(int i=1;i<=m;i++){
            if(sum[i]==-1){
                flag=1;
                break;
            }

        }
        if (flag)
        {
            cout << "-1" << endl;
        }
        else{
        for (int i=1;i<=m;i++)
        {
            cout << sum[i] << " ";
        }
        cout << endl;
        }
    }
}