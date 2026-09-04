#include<bits/stdc++.h>
using namespace std;
int n,m;
char ar[1001][1001];
int vis[1001][1001];
vector<char>path;
char br[1001][1001];
bool isValid(int x,int y){
    if(x<1 || x>n|| y<1 || y>m){
        return false;
    }
    if(vis[x][y]==1 || ar[x][y]=='#'){
        return false;
    }
    return true;
}
bool dfs(int x,int y){
    vis[x][y]=1;
    queue<pair<int,int>>q;
    q.push({x,y});
    while(!q.empty()){
        int curx=q.front().first;
        int cury=q.front().second;
        q.pop();
        if(ar[curx][cury]=='B'){
            while(1){
                path.push_back(br[curx][cury]);

                if(path.back()=='L')
                cury++;
                if(path.back()=='R')
                cury--;
                if(path.back()=='U')
                curx++;
                if(path.back()=='D')
                curx--;

                if(curx==x && cury==y){
                    break;
                }
            }
            return true;
        }
        if(isValid(curx,cury-1)){
            br[curx][cury-1]='L';
            vis[curx][cury-1]=1;
            q.push({curx,cury-1});
        }
        if(isValid(curx,cury+1)){
            br[curx][cury+1]='R';
            vis[curx][cury+1]=1;
            q.push({curx,cury+1});
        }
        if(isValid(curx-1,cury)){
            br[curx-1][cury]='U';
            vis[curx-1][cury]=1;
            q.push({curx-1,cury});
        }
        if(isValid(curx+1,cury)){
            br[curx+1][cury]='D';
            vis[curx+1][cury]=1;
            q.push({curx+1,cury});
        }
    }
    return false;
    
}
int main(){
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>ar[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
           if(ar[i][j]=='A'){
            x=i;
            y=j;
            
           }
        }
    }
    if(dfs(x,y)){
                cout<<"YES"<<endl;
                cout<<path.size()<<endl;
                while(path.size()>0){
                    cout<<path.back();
                    path.pop_back();
         }
    }
    else
    cout<<"NO"<<endl;
   
    
}