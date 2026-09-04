// #include <bits/stdc++.h>
// using namespace std;

// int arr[100001], st[400004];

// // Build Segment Tree
// void buildtree(int si, int ss, int se) {
//     if (ss == se) {
//         st[si] = arr[ss];
//         return;
//     }
//     int mid = (ss + se) / 2;
//     buildtree(2 * si, ss, mid);
//     buildtree(2 * si + 1, mid + 1, se);
//     st[si] = min(st[2 * si], st[2 * si + 1]);
// }

// // Query for the minimum in a range [qs, qe]
// int querry(int si, int ss, int se, int qs, int qe) {
//     if (ss > qe || se < qs) {
//         return INT_MAX;
//     }
//     if (ss >= qs && se <= qe) {
//         return st[si];
//     }
//     int mid = (ss + se) / 2;
//     return min(querry(2 * si, ss, mid, qs, qe), querry(2 * si + 1, mid + 1, se, qs, qe));
// }

// int main() {
//     #ifndef ONLINE_JUDGE
//     freopen("input2.txt", "r", stdin);
//     freopen("output2.txt", "w", stdout);
//     #endif
//     string s;
//     int k=2;
//     cin >> s;

//     s += "$";  // Add a unique character to mark the end of the string
//     int n = s.size();
//     vector<int> p(n), c(n);

//     // Build suffix array
//     {
//         vector<pair<char, int>> a(n);
//         for (int i = 0; i < n; i++) {
//             a[i] = {s[i], i};
//         }

//         sort(a.begin(), a.end());
//         for (int i = 0; i < n; i++) p[i] = a[i].second;
//         c[p[0]] = 0;
//         for (int i = 1; i < n; i++) {
//             if (a[i].first == a[i - 1].first)
//                 c[p[i]] = c[p[i - 1]];
//             else
//                 c[p[i]] = c[p[i - 1]] + 1;
//         }
//     }

//     int curr_k = 0;
//     while ((1 << curr_k) < n) {
//         vector<pair<pair<int, int>, int>> a(n);
//         for (int i = 0; i < n; i++) {
//             a[i] = {{c[i], c[(i + (1 << curr_k)) % n]}, i};
//         }

//         sort(a.begin(), a.end());
//         for (int i = 0; i < n; i++) p[i] = a[i].second;

//         c[p[0]] = 0;
//         for (int i = 1; i < n; i++) {
//             if (a[i].first == a[i - 1].first)
//                 c[p[i]] = c[p[i - 1]];
//             else
//                 c[p[i]] = c[p[i - 1]] + 1;
//         }
//         curr_k++;
//     }

//     // Build LCP array
//     vector<int> lcp(n);
//     curr_k = 0;
//     vector<int> rank(n);
//     for (int i = 0; i < n; i++) rank[p[i]] = i;
//     for (int i = 0; i < n - 1; i++) {
//         int j = p[rank[i] - 1];
//         while (s[i + curr_k] == s[j + curr_k]) curr_k++;
//         lcp[rank[i]] = curr_k;
//         if (curr_k > 0) curr_k--;
//     }

//     // Copy LCP array to Segment Tree array (1-indexed)
//     for (int i = 1; i < n; i++) {
//         arr[i] = lcp[i];
//     }
//     buildtree(1, 1, n - 1);
//     int i=count(s.begin(),s.end(),s[0]);
//     // Find the longest substring occurring at least k times
//     int maxLen = 0, startIdx = -1;
//     for (int i = 1; i <= n - k; i++) {
//         // Query the minimum LCP in the range [i, i + k - 2]
//         int minLcp = querry(1, 1, n - 1, i, i + k - 2);
        
//         if (minLcp > maxLen) {
//             maxLen = minLcp;
//             startIdx = p[i];
//         }
//     }
//     if(i==n-1){
//         cout<<s.substr(0,i-k+1);
//     }
//     // If no valid substring is found, print -1
//     else if (maxLen == 0) {
//         cout << -1 << endl;
//     } else {
//         // Output the found substring
//         cout << s.substr(startIdx, maxLen) << endl;  // Correct substring length
//     }

//     return 0;
// }
#include <bits/stdc++.h>
using namespace std;
#define int long long

bool compare(const pair<pair<int, int>, int>& a1, const pair<pair<int, int>, int>& a2) {
    if (a1.first.first != a2.first.first) {
        return a1.first.first < a2.first.first;
    }
    return a1.first.second < a2.first.second;
}

int32_t main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    string s;
    int k=2; // Minimum number of occurrences
    cin >> s;
    s += "$";
    int n = s.size();
    vector<int> p(n), c(n);

    // Initial sorting by first character
    {
        vector<pair<char, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {s[i], i};
        }

        sort(a.begin(), a.end());

        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }
        c[p[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
    }

    int curr_k = 0;
    while ((1 << curr_k) < n) {
        vector<pair<pair<int, int>, int>> a(n);

        for (int i = 0; i < n; i++) {
            a[i] = {{c[i], c[(i + (1 << curr_k)) % n]}, i};
        }

        sort(a.begin(), a.end(), compare);

        for (int i = 0; i < n; i++) {
            p[i] = a[i].second;
        }

        c[p[0]] = 0;

        for (int i = 1; i < n; i++) {
            if (a[i].first == a[i - 1].first) {
                c[p[i]] = c[p[i - 1]];
            } else {
                c[p[i]] = c[p[i - 1]] + 1;
            }
        }
        curr_k++;
    }

    // Build LCP array
    vector<int> lcp(n);
    curr_k = 0;
    vector<int> rank(n);
    for (int i = 0; i < n; i++) {
        rank[p[i]] = i;
    }
    for (int i = 0; i < n - 1; i++) {
        int j = p[rank[i] - 1];
        while (s[i + curr_k] == s[j + curr_k]) {
            curr_k++;
        }
        lcp[rank[i]] = curr_k;
        if (curr_k > 0) {
            curr_k--;
        }
    }
    int i=count(s.begin(),s.end(),s[0]);
    //cout<<i<<endl;
    // Find the longest substring that occurs >= k times
    int maxLen = 0;
    int index = -1;

    for (int i = 1; i <= n - k; i++) { // Sliding window over LCP array
        int minLcp = lcp[i];
        for (int j = i; j < i + k - 1; j++) {
            minLcp = min(minLcp, lcp[j]);
        }
        if (minLcp > maxLen) {
            maxLen = minLcp;
            index = p[i];
        }
    }
    if(i==n-1){
        cout<<s.substr(0,i-k+1);
    }
    else if (maxLen == 0) {
        cout << -1 << endl;
    } else {
        cout << s.substr(index, maxLen) << endl;
    }

    return 0;
}
