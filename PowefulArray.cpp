#include<bits/stdc++.h>
#define ll long long
#define Block 1000
using namespace std;
struct query {
    ll l;
    ll r;
    ll i;
};
query Q[200008];
ll ar[200008], b[200008], ans[200008], freq[1000008];
ll sum = 0;
 
bool comp(query a, query b) {
    if (a.l / Block != b.l / Block) {
        return a.l / Block < b.l / Block;
    }
    return a.r < b.r;
}
 
void add(ll pos)
{
    ll ele = ar[pos];
    ll preFreq=freq[ele];
    sum-=preFreq*preFreq*ele;
    ll currF=++freq[ele];
    sum += currF*currF*ele;
    
}
void remove(ll pos)
{
    ll ele = ar[pos];
    ll preFreq=freq[ele];
    sum-=preFreq*preFreq*ele;
    ll currF=--freq[ele];
    sum += currF*currF*ele;
}

 
int32_t main() {
     
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
 
    ll n, q;
    cin >> n >> q;
   
      for(ll i=0;i<n;i++){
        cin>>ar[i];
      }
 
    for (ll i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--;
        Q[i].r--;
    }
 
    sort(Q, Q + q, comp);
 
    ll ML = 0, MR = -1;
 
    for (ll i = 0; i < q; i++) {
        ll L = Q[i].l;
        ll R = Q[i].r;
        while (ML > L) {
            ML--;
            add(ML);
        }
        while (MR < R) {
            MR++;
            add(MR);
        }
        while (ML < L) {
            remove(ML);
            ML++;
        }
        while (MR > R) {
            remove(MR);
            MR--;
        }
        ans[Q[i].i] = sum;
    }
    for (ll i = 0; i < q; i++) {
        cout << ans[i] <<"\n";
    }
 
    return 0;
}