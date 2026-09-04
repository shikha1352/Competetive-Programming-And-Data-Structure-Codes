#include<bits/stdc++.h>
using namespace std;
struct edge{
    int a,b,w;
};
edge ar[100000];
int par[100000];
bool comp(edge a,edge b){
    if(a.w<b.w)
        return true;
    return false;
}
int find(int a){
    if(par[a]==1)
        return a;
    return par[a]=find(par[a]);
}
void merge(int a,int b)
{
    par[a]=b;
}
int main(){
    int n,m;
    cin>>n>>m;
    int sum=0;
    memset(par,-1,sizeof(par));
    for(int i=0;i<m;i++){
        cin>>ar[i].a>>ar[i].b>>ar[i].w;
    }
    sort(ar,ar+m,comp);
    for(int i=0;i<m;i++){
        int x=find(ar[i].a);
        int y=find(ar[i].b);
        if(x!=y){
            sum+=ar[i].w;
            merge(x,y);
        }
    }
    cout<<sum<<endl;
}