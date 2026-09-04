#include<bits/stdc++.h>
using namespace std;
const int mx = 100006;

struct Trie {
    int g[mx][26];
    int stateCount;
    
    Trie() {
        clear();
    }
    
    void clear() {
        memset(g[0], -1, sizeof g[0]);
        stateCount = 1;
    }
    
    void add(char * s) {
        int state = 0; 
        for (; *s; s++) {
            int next = (*s - 'a');
            if (g[state][next] == -1) {
                g[state][next] = stateCount;
                memset(g[stateCount], -1, sizeof g[stateCount]);
                stateCount++;
            }
            state = g[state][next];
        }
    }
};

Trie prefixTrie, suffixTrie;
int start[26];

void suffixDfs(int state, int depth) {
    for (int e = 0; e < 26; ++e) {
        if (suffixTrie.g[state][e] == -1) continue;
        if (depth >= 1) {
            start[e]++;
        }
        suffixDfs(suffixTrie.g[state][e], depth + 1);
    }
}

long long prefixDfs(int state, int depth) {
    long long ans = 0;
    if (depth >= 1) ans += suffixTrie.stateCount - 1;
    for (int e = 0; e < 26; ++e) {
        if (prefixTrie.g[state][e] == -1) continue;
        if (depth >= 1) {
            ans -= start[e];
        }
        ans += prefixDfs(prefixTrie.g[state][e], depth + 1);
    }
    return ans;
}

int main(){
    int P, S;
    while (scanf("%d %d ", &P, &S) == 2) {
        if (P == 0 and S == 0) break;
        
        prefixTrie.clear();
        suffixTrie.clear();
        for (int i = 0; i < 26; ++i) start[i] = 0;
        
        static char buffer[1024];
        for (int i = 0; i < P; ++i) {
            gets(buffer);
            prefixTrie.add(buffer);
        }
        for (int i = 0; i < S; ++i) {
            gets(buffer);
            int n = strlen(buffer);
            reverse(buffer, buffer + n);
            suffixTrie.add(buffer);
        }
        suffixDfs(0, 0);
        long long ans = prefixDfs(0, 0);
        
        cout<<ans<<endl;
        
    }

    
    return 0;
}