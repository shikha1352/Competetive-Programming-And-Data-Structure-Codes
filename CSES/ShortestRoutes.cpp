#include<bits/stdc++.h>
using namespace std;
#define ll long long int

vector<pair<ll,ll>> graph[2000002];
set<pair<ll,ll>> st;

int main() {
    ll n, m;
    cin >> n >> m;
    while (m--) {
        ll a, b, w;
        cin >> a >> b >> w;
        graph[a].push_back({b, w});
    }
    
    
    vector<ll> dist(n + 1, LLONG_MAX);
    st.insert({0, 1});
    dist[1] = 0;
    while (!st.empty()) {
        auto it = st.begin();
        ll node = it->second;
        ll dis = it->first;
        st.erase(it);
        for (pair<ll, ll> child : graph[node]) {
            ll adjnode = child.first;
            ll edgw = child.second;
            if (dis + edgw < dist[adjnode]) {
                
                st.erase({dist[adjnode], adjnode}); 
                dist[adjnode] = dis + edgw; 
                st.insert({dist[adjnode], adjnode}); 
            }
        }
    }

    
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;

    return 0;
}
