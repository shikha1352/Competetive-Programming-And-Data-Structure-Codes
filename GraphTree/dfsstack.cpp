 #include <bits/stdc++.h>
using namespace std;
const int N = 1001;
vector<int> arr[N];
int visited[N] = {0};
void dfs(int src)
{
    visited[src] = 1;
    stack<int> st;
    st.push(src);

    while (!st.empty())
    {
        int current = st.top();
        cout << current << " ";
        st.pop();
        for (auto child : arr[current])
        {
            if(visited[child]==0){
            visited[child] = 1;
            st.push(child);
            }
        }
    }
    cout<<endl;
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        arr[a].push_back(b);
        arr[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) {
    cout << "Adjacent vertices of node " << i << ": ";
    for (int j = 0; j < arr[i].size(); j++) {
        cout << arr[i][j] << " ";
    }
    cout << endl;
}
    dfs(1);
}

