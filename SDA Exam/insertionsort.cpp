#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, p = 0;
    cout << "Enter size:" << endl;
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        p++;
        int flag = 0;
        cout << "The array after pass:" << p << endl;
        while (j >= 0)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
                flag = 1;
            }
            if (flag == 1)
            {
                a[j] = temp;
                for (int k = 0; k < n; k++)
                {

                    cout << a[k] << " ";
                }
                cout << endl;
            }

            j--;
        }
        if (flag == 0)
        {
            break;
        }
    }
    cout << "The array after insertion sort:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
