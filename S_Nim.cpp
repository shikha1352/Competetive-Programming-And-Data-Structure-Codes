#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;
const int mx=100001;
int a[101];
int k;
int grundy[mx];
int calculateMex(set<int>st){
    int max=0;
    while(st.find(max)!=st.end())
        max++;
    return (max);
}
int calculateGrundy(int x){
    if(x<a[0])
    {
        return 0;
    }
    if(grundy[x]!=-1){
        return grundy[x];
    }
    set<int>st;
    for(int i=0;i<k;i++){
        if(x>=a[i])
        st.insert(calculateGrundy(x-a[i]));
    }
    grundy[x]=calculateMex(st);
    return grundy[x];
}
void solve() {

    int l;
    cin>>l;
    int sum=0;
    for(int i=0;i<l;i++){
        int x;
        cin>>x;
        sum=sum^calculateGrundy(x);
    }
    if(sum==0){
        cout<<"L";
    }
    else{
        cout<<"W";
    }
}
int32_t main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    memset(grundy,-1,sizeof(grundy));

    cin>>k;
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    sort(a,a+k);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
