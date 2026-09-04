
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;

void solve() {
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    int x=__gcd(n,m);
    int k=m/x;
    if(__builtin_popcount(k)>1){
        cout<<-1<<endl;
    }
    else{
        int y=n%m;
            while(y){
                 ans+=y;
                y*=2;
                if(y>=m)
                y-=m;

            }
            cout<<ans<<endl;

    }

}

int32_t main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
