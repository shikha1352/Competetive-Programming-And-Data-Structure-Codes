#include<bits/stdc++.h>
using namespace std;
vector < vector <pair <int, int> > > graph;
int visited[30005]={0};
long long maxD;
int start=-1;
void dfs(int node,long long dist){
    visited[node]=1;
    if(dist>maxD){
        maxD=dist;
        start=node;
    }
    int x;
    int w;
    for (int i = 0; i < graph[node].size(); i++) {
		x = graph[node][i].first;
		w = graph[node][i].second;

		if(visited[x] == 0) {
			dfs(x, dist+w);
		}

	}
}

int main(){
    int t;
    cin>>t;
    int cs=1;
    while(t--){
        int n;
        cin>>n;
        graph.clear();
        graph.resize(n + 1);
        for(int i=0;i<n-1;i++){
            int x,y,w;
            cin>>x>>y>>w;
            graph[x].push_back(make_pair(y, w));
			graph[y].push_back(make_pair(x, w));
            
        }
             maxD=-1;
            memset(visited, 0, sizeof(visited));
            dfs(0,0);
            
            maxD=-1;
            memset(visited, 0, sizeof(visited));
		    dfs(start, 0);

            cout<<"Case "<<cs++<<": "<<maxD<<endl;
    }
    
}