#include <bits/stdc++.h>
using namespace std;
void computeLPSArray(string pat, int M, int* lps){
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < M) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }
}
vector<int> KMPSearch(string pat, string txt)
{
    int M = pat.size();
    int N = txt.size();
    int lps[M];
    computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;
    vector<int> indices; // Vector to store indices

    while ((N - i) >= (M - j)) {
        if (pat[j] == txt[i]) {
            j++;
            i++;
        }
        if (j == M) {
            // Pattern found
            indices.push_back(i - j);
            j = lps[j - 1];
        }
        else if (i < N && pat[j] != txt[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return indices;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        string txt,pat;
   cin>>txt>>pat;
    vector<int> occurrences = KMPSearch(pat, txt);
    
    if (!occurrences.empty()) {
        cout<<occurrences.size()<<endl;
        for (int i = 0; i < occurrences.size(); ++i) {
            cout << occurrences[i]+1<<" ";
          
        }
        cout << endl;
    } else {
        cout << "Not Found" << endl;
    }
    }
   

    return 0;
}
