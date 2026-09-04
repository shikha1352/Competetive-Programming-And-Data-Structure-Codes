#include <bits/stdc++.h>
using namespace std;

// Function to compute the LPS (Longest Prefix Suffix) array
void computeLPSArray(string pat, int M, vector<int>& lps) {
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Function to solve the problem based on the LPS array
void findSubstring(string s) {
    int n = s.length();
    vector<int> lps(n, 0);

    // Step 1: Compute the LPS array for the string `s`
    computeLPSArray(s, n, lps);

    
    int len = lps[n - 1]; 

    // If there's no valid prefix-suffix, print "Just a legend"
    if (len == 0) {
        cout << "Just a legend" << endl;
        return;
    }

    while (len > 0) {
        
        for (int i = 0; i < n - 1; i++) {
            if (lps[i] == len) {
                cout << s.substr(0, len) << endl;
                return;
            }
        }
        // If not found, reduce the length and check again
        len = lps[len - 1];
    }

    // If no valid substring is found, print "Just a legend"
    cout << "Just a legend" << endl;
}

int main() {
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    string s;
    cin >> s; // Read the input string
    findSubstring(s); // Call the function to find the required substring
    return 0;
}
