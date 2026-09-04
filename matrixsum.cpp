#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1025; 

int BIT[MAXN][MAXN]; 
int N; 


void update(int x, int y, int val) {
    for (int i = x; i <= N; i += i & -i) {
        for (int j = y; j <= N; j += j & -j) {
            BIT[i][j] += val;
        }
    }
}


int prefixSum(int x, int y) {
    int sum = 0;
    for (int i = x; i > 0; i -= i & -i) {
        for (int j = y; j > 0; j -= j & -j) {
            sum += BIT[i][j];
        }
    }
    return sum;
}


int rangeSum(int x1, int y1, int x2, int y2) {
    return prefixSum(x2, y2) - prefixSum(x1 - 1, y2) - prefixSum(x2, y1 - 1) + prefixSum(x1 - 1, y1 - 1);
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        cin >> N;
        
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                BIT[i][j] = 0;
            }
        }
        
        string command;
        while (cin >> command && command != "END") {
            if (command == "SET") {
                int x, y, num;
                cin >> x >> y >> num;
                update(x + 1, y + 1, num); 
            } else if (command == "SUM") {
                int x1, y1, x2, y2;
                cin >> x1 >> y1 >> x2 >> y2;
                cout << rangeSum(x1 + 1, y1 + 1, x2 + 1, y2 + 1) << endl; 
            }
        }
        
        cout << endl; 
    }
    
    return 0;
}