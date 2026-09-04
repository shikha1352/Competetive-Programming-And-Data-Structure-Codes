#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> graph;
vector<int> in, res;

void khan_with_priority_queue(int n) {
    priority_queue<int, vector<int>, greater<int>> pq;  // Min-heap for lexicographical order

    // Push nodes with in-degree 0 to the priority queue
    for (int i = 0; i < n; i++) {
        if (in[i] == 0) {
            pq.push(i);
        }
    }

    while (!pq.empty()) {
        int cur = pq.top();  // Get the smallest element
        pq.pop();
        res.push_back(cur);

        for (int child : graph[cur]) {
            in[child]--;
            if (in[child] == 0) {
                pq.push(child);
            }
        }
    }
}

int main() {
    // #ifndef ONLINE_JUDGE
    // freopen("input2.txt", "r", stdin);
    // freopen("output2.txt", "w", stdout);
    // #endif
    int case_num = 0;
    string line;

    while (true) {
        // Read number of beverages
        int n;
        if (!(cin >> n)) break;  // End of input (EOF)
        cin.ignore();

        case_num++;

        // Map for beverage name to index and reverse mapping
        map<string, int> name_to_index;
        map<int, string> index_to_name;

        for (int i = 0; i < n; i++) {
            string beverage;
            getline(cin, beverage);
            name_to_index[beverage] = i;
            index_to_name[i] = beverage;
        }

        // Read number of relationships
        int m;
        cin >> m;
        cin.ignore();

        // Initialize graph and in-degree array
        graph.assign(n, vector<int>());
        in.assign(n, 0);
        res.clear();

        // Read relationships
        for (int i = 0; i < m; i++) {
            string b1, b2;
            cin >> b1 >> b2;
            int u = name_to_index[b1];
            int v = name_to_index[b2];
            graph[u].push_back(v);
            in[v]++;
        }
        cin.ignore();

        // Perform topological sorting with priority queue
        khan_with_priority_queue(n);

        // Output in the required format
        cout << "Case #" << case_num << ": Dilbert should drink beverages in this order:";
        for (int i = 0; i < res.size(); i++) {
            cout << " " << index_to_name[res[i]];
        }
        cout << ".\n\n";
    }

    return 0;
}
