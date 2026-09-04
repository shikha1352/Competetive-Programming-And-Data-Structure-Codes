#include<bits/stdc++.h>
using namespace std;
const int mx=1001;
vector<int>arr[mx];
int n;
int cont[mx];
void initi ()
{
   for(int i=0;i<mx;i++)
   {
       arr[i].clear();
       cont[i]=0;
   }
}

void bfs(int source){
    int visited[mx];
    for(int i=1;i<=n;i++){
        visited[i]=0;
    }
    queue<int>q;
    q.push(source);
    visited[source]=1;
    cont[source]++;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(int i=0;i<arr[current].size();i++){
                int v=arr[current][i];
            if(visited[v]==0){
                q.push(v);
                visited[v]=1;
                cont[v]++;
            }
        }
    }

}
int main(){
    int t,cs=1;
    cin>>t;
    while(t--){
        initi();
        int k,m,a,b;
        cin>>k>>n>>m;

        int cities[k];
        for(int i=0;i<k;i++){
            cin>>cities[i];
        }
        for(int i=0;i<m;i++){
            cin>>a>>b;
            arr[a].push_back(b);
        }
        for(int i=0;i<k;i++){
            bfs(cities[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(cont[i]==k){
                ans++;
            }
        }
        cout<<"Case "<<cs++<<": "<<ans<<endl;

    }

}
