#include <bits/stdc++.h>
using namespace std;
int visited[5] = {0};
queue<int> q;
int main() {
    int graph[5][5] = {
        {0, 1, 0, 0, 1},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 1, 0},
        {0, 1, 1, 0, 1},
        {1, 1, 0, 1, 0}
    };

    visited[0] = 1;
    q.push(0);

    while (!q.empty()) {
        int current = q.front();
        cout << q.front() << " ";
        q.pop();

        for (int i = 0; i < 5; i++) {
            if (graph[current][i] == 1 && visited[i] == 0) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }

    return 0;
}
