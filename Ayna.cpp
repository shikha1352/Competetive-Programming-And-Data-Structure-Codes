#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define out(x) cout<<x<<endl
#define lli long long int
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define mod 1000000007
const int mx=10000;
int isPrime[mx];
void seive(){
    fill(isPrime, isPrime + mx, 1);
    isPrime[0]=isPrime[1]=0;
    for(int i=0;i*i<=mx;i++){
        if(isPrime[i]){
            for(int j=i*i;j<=mx;j+=i){
                isPrime[j]=0;
            }
        }
    }
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    if(s.find("ps") != string::npos) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }

}
int32_t main() {

    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
