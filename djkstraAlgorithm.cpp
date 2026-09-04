#include<bits/stdc++.h>
using namespace std;
#define V 9
void print(int dst[]){
    cout << "Vertex \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout << i << " \t\t\t\t" << dst[i] << endl;
}

int findMin(int dst[],bool visited[]){
    int min=INT_MAX,min_index;
    for(int i=0;i<V;i++){
        if(visited[i]==false && dst[i]<=min){
            min=dst[i];
            min_index=i;
        }
    }
    return min_index;
}
void djkstra(int graph[V][V],int source){
        int dst[V];
        bool visited[V];
        for(int i=0;i<V;i++){
            dst[i]=INT_MAX;
            visited[i]=false;
        }
        dst[source]=0;
        for(int i=0;i<V-1;i++){
            int u=findMin(dst,visited);
            visited[u]=true;

             for(int v=0;v<V;v++){
             if (!visited[v] && graph[u][v]
                && dst[u] != INT_MAX
                && dst[u] + graph[u][v] < dst[v])
                dst[v] = dst[u] + graph[u][v];
        }
        }
        print(dst);
       
}
int main(){
    int graph[V][V]={ { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    djkstra(graph,0);
}