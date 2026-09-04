#include<bits/stdc++.h>
using namespace std;
#define int long long
int k;
string s1,s2;
set<int> a;
bool good(char ch) {
    return s2[ch-'a'] == '1';
}
struct node {
    node *next[30];
};
 
int32_t main(){
     node *head = new node();
    cin >> s1;
    cin >> s2;
    cin >> k;
    int ans = 0;
    for (int i = 0; i < s1.size(); i++) {
        int cnt = 0;
        node *p = head;
        for (int j = i; j < s1.size(); j++) {
            if (!good(s1[j])) {
                cnt ++;
            }
            int c = s1[j] - 'a';
            if (cnt > k) break;
            if (p->next[c] == NULL) {
                p->next[c] = new node();
                ans ++;
            } 
            p = p->next[c];
        }
    }
    cout << ans;

   return 0;
}
