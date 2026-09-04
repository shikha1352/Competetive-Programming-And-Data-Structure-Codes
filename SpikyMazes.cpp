#include<bits/stdc++.h>
using namespace std;
int m,n;
bool dfs(vector<vector<char> > &graph, int i, int j, int p, vector< vector<bool> > &visit){
	if(i< 0 || i>=m || j<0 || j>=n || p<0 || graph[i][j] == '#' ) return false;
	if(graph[i][j] == 'x' ) return true;
	if(!visit[i][j]){
	visit[i][j]=true;
	if(dfs(graph,i+1,j,(graph[i][j]=='s')?p-1:p,visit)) return true;
	if(dfs(graph,i,j+1,(graph[i][j]=='s')?p-1:p,visit)) return true;
	if(dfs(graph,i,j-1,(graph[i][j]=='s')?p-1:p,visit)) return true;
	if(dfs(graph,i-1,j,(graph[i][j]=='s')?p-1:p,visit)) return true;
	graph[i][j]='#';
	visit[i][j]=false;
}
	return false;
}
int main() {
	int a,b,p;
	cin>>m>>n>>p;
	vector<vector<char> > graph(m,vector<char>(n,32)); 
	vector<vector<bool> > visit(m,vector<bool>(n,0)); 
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			
			cin>>graph[i][j];
			if(graph[i][j] == '@'){
				a=i;
				b=j;
			}			
		}	
	}
	if(dfs( graph, a, b,(int) p/2, visit))
	{
	cout<<"SUCCESS"<<endl;
	}
	else{
	cout<<"IMPOSSIBLE"<<endl;
	}
	return 0;
}