#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// Memoization map for Grundy numbers
unordered_map<long long, int> grundyMap;

// Function to calculate Grundy number iteratively
int calculateGrundy(long long x) {
    if (x < 4) return 0; // No valid moves if x < 4

    if (grundyMap.count(x)) return grundyMap[x]; // Return cached value if exists

    unordered_set<int> reachableGrundy;

    // Generate all valid moves and calculate reachable Grundy numbers
    for (long long y = x / 4; y <= x / 2; ++y) {
        if (y >= 4) {
            reachableGrundy.insert(calculateGrundy(y));
        }
    }

    // Calculate mex (minimum excluded value)
    int grundy = 0;
    while (reachableGrundy.count(grundy)) {
        ++grundy;
    }

    // Store the result in the memoization map
    grundyMap[x] = grundy;
    return grundy;
}

int main() {
	#ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
    int n;  // Number of piles
    cin >> n;

    vector<long long> piles(n);  // Sizes of piles
    for (int i = 0; i < n; ++i) {
        cin >> piles[i];
    }

    int nimSum = 0;

    // Calculate the Nim-sum using Grundy numbers
    for (int i = 0; i < n; ++i) {
        nimSum ^= calculateGrundy(piles[i]);
    }

    // Determine the winner
    if (nimSum == 0) {
        cout << "Rublo" << endl; // Second player wins
    } else {
        cout << "Furlo" << endl; // First player wins
    }

    return 0;
}
