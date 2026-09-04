#include <bits/stdc++.h>
using namespace std;
#define ll long long
int32_t main() {  
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                st.push('(');
            }
            else {
                if(!st.empty() && st.top()=='('){
                    st.pop();
                }
            }
        }
        cout<<st.size()<<endl;
    }
    return 0;
}
