#include<bits/stdc++.h>
using namespace std;
int n,m;
int vis[50][50];
int ar[50][50];
bool isValid(int x,int y){
    if(x>n || x<1 || y>m || y<1){
        return false;
    }
    if(vis[x][y]==1 || ar[x][y]==0){
        return false;
    }
    return true;
}
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void dfs(int x,int y){
    vis[x][y]=1;
    for(int i=0;i<4;i++){
        if(isValid(x+dx[i],y+dy[i])){
            dfs(x+dx[i],y+dy[i]);
        }
    }
}
int main(){
    cin>>n>>m;


    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            vis[i][j]=0;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ar[i][j];
        }
    }
    int cc=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(vis[i][j]==0 && ar[i][j]==1){
            dfs(i,j);
            cc++;
           }
        }
    }
   cout<<cc<<endl;
}