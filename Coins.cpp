#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(n) n.begin(), n.end()
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
const ll mod = 1e18;
int dx[] = {-1,0,+1,0};
int dy[] = {0,+1,0,-1};
stack<int>st;
int vis[3]={0};
vector<vector<int>>graph;
map<char,int>mp;
map<int,char>x;

void dfs(int node){
    vis[node]=1;
    for(auto it:graph[node]){
        if(vis[it]==0){
            dfs(it);
        }
    }
    st.push(node);
}
void solve() {
    char s[3][3];
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cin>>s[i][j];
        }
    }
    mp['A']=0;
    mp['B']=1;
    mp['C']=2;
    x[0]='A';
    x[1]='B';
    x[2]='C';
    graph.resize(3);
    if(s[0][1]=='>'){
        graph[mp[s[0][0]]].push_back(mp[s[0][2]]);
    }
    else if(s[0][1]=='<'){
        graph[mp[s[0][2]]].push_back(mp[s[0][0]]);
    }
    if(s[1][1]=='>'){
        graph[mp[s[1][0]]].push_back(mp[s[1][2]]);
    }
    else if(s[1][1]=='<'){
        graph[mp[s[1][2]]].push_back(mp[s[1][0]]);
    }
    if(s[2][1]=='>'){
        graph[mp[s[2][0]]].push_back(mp[s[2][2]]);
    }
    else if(s[2][1]=='<'){
        graph[mp[s[2][2]]].push_back(mp[s[2][0]]);
    }
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(vis[mp[s[i][j]]==0]){
                dfs(mp[s[i][j]]);
            }
        }
    }
    int k=0;
    for(int i=0;i<st.size();i++){
        // cout<<s[x[st.top()][k]];
        // st.pop();
        // k++;
        cout<<st.top();
    }
    
}
int32_t main() {
    
    #ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
   
        solve();
    
    return 0;
}
