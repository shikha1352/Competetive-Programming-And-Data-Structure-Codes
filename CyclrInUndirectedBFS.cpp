#include<bits/stdc++.h>
using namespace std;
/*void bfs(int node,vector<vector<int>>&graph,vector<int>&vis)
{
	queue<int>q;
	q.push(node);
	vis[node]=1;
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto it:graph[v]){
			if(!vis[it]){
				vis[it]=1;
				q.push(it);
			}
		}
	}
}
void dfs(int node,vector<vector<int>>&graph,vector<int>&vis)
{
	vis[node]=1;
	for(auto it:graph[node]){
		if(!vis[it]){
			dfs(it,graph,vis);
		}
	}
}*/

//detect cycle on bfs
/*bool bfs(int node,vector<vector<int>>&graph,vector<int>&vis){
	queue<pair<int,int>>q;
	q.push({node,-1});
	vis[node]=1;

	while(!q.empty()){
		int v=q.front().first;
		int parnt=q.front().second;
		q.pop();
		for(auto it:graph[v]){
			if(!vis[it]){
				vis[it]=1;
				q.push({it,v});
			}
			else if(it!=parnt){
				return true;
			}
		}
	}
	return false;
}*/
/*bool dfs(int node, int parent, vector<vector<int>>& graph, vector<int>& vis) {
    vis[node] = 1; // Mark the node as visited
    for (auto it : graph[node]) {
        if (!vis[it]) {
            // If not visited, recurse
            if (dfs(it, node, graph, vis)) {
                return true; // Cycle found
            }
        } else if (it != parent) {
            // If visited and not the parent, cycle detected
            return true;
        }
    }
    return false; // No cycle found
}*/
//bipertite on dfs
/*
bool bipertite(int node,int c,vector<int>&color,vector<vector<int>>&graph){
	color[node]=c;
	for(auto it:graph[node]){
		if(color[it]==-1){
			if(bipertite(it,!c,color,graph)==false){
				return false;
			}
		}
		else if(color[it]==c){
			return false;
		}
	}
	return true;
}*/
//bipertite on bfs
/*
bool bipertite(int node,int c,vector<int>&color,vector<vector<int>>&graph){
	color[node]=c;
	queue<int>q;
	q.push(node);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto it:graph[v]){
			if(color[it]==-1){
				color[it]=(!color[v]);
				q.push(it);
			}
			else if(color[it]==color[v]){
				return false;
			}
		}
	}
	return true;
}*/
//shortest path on bfs
/*void bfs(int node,vector<int>&vis,vector<vector<int>>&graph,vector<int>&dist){
	dist[node]=0;
	queue<int>q;
	q.push(node);
	while(!q.empty()){
		int v=q.front();
		q.pop();
		for(auto it:graph[v]){
			
				if((dist[v]+1)<dist[it]){
				dist[it]=dist[v]+1;
				
				q.push(it);
			
			}
			
		}
	}
}*/
//shortest path on dfs
void dfs(int node,vector<vector<int>>&graph,vector<int>&dist){
	for(auto it:graph[node]){
		if(dist[node]+1<dist[it]){
			dist[it]=dist[node]+1;
			dfs(it,graph,dist);
		}
	}
}
int32_t main(){
	#ifndef ONLINE_JUDGE
    freopen("input2.txt", "r", stdin);
    freopen("output2.txt", "w", stdout);
    #endif
	int n,m;
	cin>>n>>m;
	vector<vector<int>>graph(n+1);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int>vis(n+1,0);
	//Shortest path
	vector<int>dist(n+1,INT_MAX);
	//bfs(1,vis,graph,dist);
	dist[1]=0;
	dfs(1,graph,dist);
	for(int i=1;i<=n;i++){
		cout<<dist[i]<<" ";
	}
	cout<<endl;
	//Bipertite on bfs
	/*vector<int>color(n+1,-1);
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			if(bipertite(i,0,color,graph)){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;*/
	/*//Bipertite test on dfs
	vector<int>color(n+1,-1);
	for(int i=1;i<=n;i++){
		if(color[i]==-1){
			if(bipertite(i,0,color,graph)==true){
				cout<<"YES"<<endl;
				return 0;
			}
		}

	}
	cout<<"NO"<<endl;*/
	//vector<int>vis(n+1,0);
	//int cnt=0;
	// connected component on bfs;
	/*int cnt=0;
	for(int i=0;i<n;i++){

		if(!vis[i]){
			bfs(i,graph,vis);
			cnt++;
		}
	}*/
	//dfs connect component
	/*for(int i=0;i<n;i++){
		if(!vis[i]){
			dfs(i,graph,vis);
			cnt++;
		}
	}
	cout<<cnt<<endl;
	*/


	//cycle detection on BFS
	/*for(int i=0;i<n;i++){
		if(!vis[i]){
			if(bfs(i,graph,vis)){
				cout<<"YES"<<endl;
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;*/
	/*
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			if(dfs(i,-1,graph,vis)==true)
			{
				cout<<"YES"<<endl; 
				return 0;
			}
		}
	}
	cout<<"NO"<<endl;
	*/

}