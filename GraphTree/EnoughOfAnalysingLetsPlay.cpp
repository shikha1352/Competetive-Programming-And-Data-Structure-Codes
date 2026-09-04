#include<bits/stdc++.h>
using namespace std;
int count_winning_moves(const vector<int>& piles) {
    int nim_sum = 0;
    int count = 0;
    for (int pile : piles) {
        nim_sum ^= pile;
    }
    for (int pile : piles) {
        int new_nim_sum = nim_sum ^ pile;
        if (new_nim_sum < pile) {
            count++;
        }
    }
    return count;
}
int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n;
        cin >> n;
        vector<int> piles(n);
        for (int j = 0; j < n; ++j) {
            cin >> piles[j];
        }
        int result = count_winning_moves(piles);
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
