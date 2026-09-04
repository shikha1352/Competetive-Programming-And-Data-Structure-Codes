#include<bits/stdc++.h>
using namespace std;
#define int long long
bool compare(const pair<pair<int, int>, int>& a1, const pair<pair<int, int>, int>& a2) {
    if (a1.first.first != a2.first.first) {
        return a1.first.first < a2.first.first;
    }
    return a1.first.second < a2.first.second;
}

int32_t main() {
    string s ;
    cin>>s;
    s += "$"; 
    int n = s.size();
    vector<int> p(n), c(n); 
    {
        vector<pair<char, int> > a(n);
        for(int i = 0; i < n; i++) {
            a[i] = {s[i], i};
        }

        sort(a.begin(), a.end());

        for(int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;

        for(int i = 1; i < n; i++) {
            if(a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        } 
    }

    int k = 0;

    while((1 << k) < n) {
        vector< pair < pair<int, int> ,int> > a(n);
         
        for(int i = 0; i < n; i++) { 
            a[i] = {{c[i], c[(i + (1 << k)) % n]}, i};
        }

        sort(a.begin(), a.end(), compare);

        for(int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;

        for(int i = 1; i < n; i++) {
            if(a[i].first == a[i-1].first) {
                c[p[i]] = c[p[i-1]];
            } else {
                c[p[i]] = c[p[i-1]] + 1;
            }
        }
        k++;
    }
    vector<int> lcp(n);
    k = 0;
    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        rank[p[i]] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int j = p[rank[i] - 1];
        while (s[i + k] == s[j + k]) {
            k++;
        }
        lcp[rank[i]] = k;
        if (k > 0) {
            k--;
        }
    }
    int totalSubstrings = (n * (n - 1)) / 2;
    int lcpSum = accumulate(lcp.begin(), lcp.end(), 0LL);
    int distinctSubstrings = totalSubstrings - lcpSum;
    cout <<distinctSubstrings << endl;
    return 0;
}
