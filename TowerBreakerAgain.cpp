#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;
const int mx=100001;
vector<vector<int>>divisor(mx+1);
int grundy[mx];
void seive() {
    for (int i = 2; i <= mx; i++) {
        for (int j =i; j <= mx; j += i) {
            divisor[j].push_back(i);
        }
    }
}
int calculateMex(set<int>set){
    int mex=0;
    while(set.find(mex)!=set.end())
        mex++;
    return(mex);
}
int calculateGrundy(int x){
    if(x==1){
        return 0;
    }
    if(grundy[x]!=-1){
        return grundy[x];
    }
    set<int>st;
    for(int i=0;i<divisor[x].size();i++){
        int y=divisor[x][i];
        int z=x/y;
        if(y%2==0){
            st.insert(0);

        }
        else{
            st.insert(calculateGrundy(z));
        }
        
    }
    grundy[x]=calculateMex(st);
    return grundy[x];
}
void solve() {
    int n;
    cin>>n;
    int sum=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int y=calculateGrundy(x);
        sum=sum^y;
    }
    if(sum==0)
        cout<<"2"<<endl;
    else
        cout<<"1"<<endl;
    
}
int32_t main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    memset(grundy,-1,sizeof(grundy));
    seive();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
