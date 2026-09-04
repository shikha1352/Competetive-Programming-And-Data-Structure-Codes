#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0,count2=0,count3=0;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            v.push_back(x);
        }
        for (int i = 0; i < n - 1; i++)
        {
            if (v[i] == v[i + 1])
            {
                count++;
            }
        }
        if (count > n - 2)
        {
            cout << "-1" << endl;
        }
        else
        {
            vector<int> b;
            for (int i = 0; i < n - 1; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (v[i] == v[j])
                    {
                        if (find(b.begin(), b.end(), i) == b.end() && find(b.begin(), b.end(), j) == b.end())
                        {
                            b.push_back(i);
                            b.push_back(j);
                            count2++;
                            if(count2%2==0)
                            {
                                v[i] = 1;
                                v[j] = 3;
                            }
                            else if(count2%3==0)
                            {
                                v[i] = 2;
                                v[j] = 3;
                            }
                            else
                            {
                                v[i] = 1;
                                v[j] = 2;
                            }
                        }
                    }
                }
            }
            if(b.size()>=4)
            {
                for (int i = 0; i < n; i++)
                {
                    if (find(b.begin(), b.end(), i) == b.end())
                    {
                        if(v[i]!=1 && v[i]!=2)
                        {
                            count3++;
                            if(count3%2==0)
                            {
                                v[i] = 2;
                            }
                            else if(count3%3==0)
                            {
                                v[i] = 3;
                            }
                            else
                            {
                                v[i] = 1;
                            }
                        }
                    }
                }
                for (int i = 0; i < v.size(); i++)
                {
                    cout << v[i] << " ";
                }
                cout << endl;
            }
            else
            {
                cout<<"-1"<<endl;
            }
        }
    }
    return 0;
}
