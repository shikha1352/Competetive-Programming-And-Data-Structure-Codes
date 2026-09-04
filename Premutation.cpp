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
        int a[n+5][n];
        for(int i=1;i<=n;i++){
            for(int j=1;j<n;j++){
                cin>>a[i][j];
            }
        }
        map<int,int>m;
        map<int,int>mp;
        for(int i=1;i<=n;i++){
            m[a[i][n-1]]=i;
            mp[a[i][n-1]]++;
        }
        int indx=0,val;
        for(auto it:mp){
            if(it.second==1){
                indx=it.first;
            }
            else
            val=it.first;
        }
        for(int i=1;i<n;i++){
            cout<<a[m[indx]][i]<<" ";
        }
        cout<<val<<endl;
    }
    return 0;
}
