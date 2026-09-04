#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        int fl=0;
        for (int i = 0; i < s.size(); i++)
        {
            if ((s[i] - '0') == 1)
            {
                cnt++;
            }
        }
        if (cnt == 2)
            {
                for (int i = 0; i < s.size() - 1; i++)
                {
                    if ((s[i] - '0') == 1 && s[i + 1] - '0' == 1)
                    {
                        fl=1;
                        break;
                    }
                }
                if(fl==1){
                    cout<<"NO"<<endl;
                }
                else{
                    cout<<"YES"<<endl;
                }
            }
        else if (cnt % 2 == 0)
        {
            
            cout<<"YES"<<endl;
            
        }
        else if(cnt%2==1)
        {
            cout << "NO" << endl;
        }
    }
}