#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;
    //cin.ignore(); // consume newline character after reading t

    while (t--) {
        string keys;
        getline(cin, keys); // read the entire line including spaces

        vector<char> typedString;

        for (char key : keys) {
            if (key == 'b') {
                // Process 'b': remove the last lowercase letter
                if (!typedString.empty()) {
                    for (int i = typedString.size() - 1; i >= 0; i--) {
                        if (islower(typedString[i])) {
                            typedString.erase(typedString.begin() + i);
                            break;
                        }
                    }
                }
            } else if (key == 'B') {
                // Process 'B': remove the last uppercase letter
                if (!typedString.empty()) {
                    for (int i = typedString.size() - 1; i >= 0; i--) {
                        if (isupper(typedString[i])) {
                            typedString.erase(typedString.begin() + i);
                            break;
                        }
                    }
                }
            } else {
                // Add the key to the typed string if it's not 'b' or 'B'
                if (key != 'b' && key != 'B') {
                    typedString.push_back(key);
                }
            }
        }

        // Print the final typed string
        for (char c : typedString) {
            cout << c;
        }
        cout << endl;
    }

    return 0;
}
