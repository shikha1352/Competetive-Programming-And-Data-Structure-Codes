#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Define a struct to represent an event
struct Event {
    int a; // Start time
    int b; // End time or power requirement
    int type; // Type of event: 1 for power request, 0 for power addition

    // Comparator for sorting events
    bool operator<(const Event& other) const {
        return a < other.a;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, m, L;
        cin >> n >> m >> L;

        vector<Event> events;

        // Reading the power request events
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            events.push_back({a, b, 1});
        }

        // Reading the power addition events
        for (int i = 0; i < m; ++i) {
            int a, b;
            cin >> a >> b;
            events.push_back({a, b, 0});
        }

        // Sorting events by start time
        sort(events.begin(), events.end());

        int k = 1; // Initial power available
        priority_queue<int> pwr; // Max-heap to store available powers
        bool valid = true;

        // Process each event
        for (size_t i = 0; i < events.size(); ++i) {
            int a = events[i].a;
            int b = events[i].b;
            int type = events[i].type;

            if (type == 0) {
                // Add power to the heap
                pwr.push(-b);
            } else {
                // Consume power for the request
                while (!pwr.empty() && k < b - a + 2) {
                    k -= pwr.top();
                    pwr.pop();
                }
                if (k < b - a + 2) {
                    // Not enough power
                    cout << -1 << '\n';
                    valid = false;
                    break;
                }
            }
        }

        // If all requests were satisfied, print remaining unused power sources
        if (valid) {
            cout << m - pwr.size() << '\n';
        }
    }

    return 0;
}
