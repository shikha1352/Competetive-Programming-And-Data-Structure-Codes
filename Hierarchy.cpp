#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;

void solve() {
    ll n;
    cin>>n;
    vector<ll>q(n);
    for(int i=0;i<n;i++){
        cin>>q[i];
    }
    int p;
    cin>>p;
    unordered_map<ll,ll>parnt;
    ll cost=0;
    vector<int>cst(n,-1);
    while(p--){
        ll a,b,c;
        cin>>a>>b>>c;
        a--;
        b--;
        if(parnt.find(b)==parnt.end() && q[a]>q[b])
        {
            cost+=c;
            parnt[b]=a;
            cst[b]=c;
        }
        else if(parnt.find(b)!=parnt.end() && q[a]>q[b] && cst[b]>c){
            cost-=cst[b];
            cost+=c;
            parnt[b]=a;
            cst[b]=c;
        }

    }
    if(parnt.size()==n-1){
        cout<<cost<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

int32_t main() {
     #ifndef ONLINE_JUDGE
    freopen("input1.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    
        solve();
    
    return 0;
}