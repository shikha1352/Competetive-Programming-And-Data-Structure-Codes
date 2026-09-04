#include<bits/stdc++.h>
using namespace std;
#define ll long long int
struct edge{
    int a;
    int b;
    ll w;
};
vector<edge>ar;
int par[200001];
bool comp(edge a,edge b){
    return a.w<b.w;
}
int find(int a){
    if(par[a]==-1){
        return a;
    }
    return(par[a]=find(par[a]));
}
bool merge(int a , int b){
	a = find(a);
	b = find(b);
	
	if(a == b) return false;
	
	par[a] = b;
	return true;
}

int32_t main(){
    int n,m;
    cin>>n>>m;
    ar.resize(n+1);
    for(int i=0;i<n;i++){
        par[i]=-1;
    }
    edge temp;
    for(int i=0;i<m;i++){
        cin>>temp.a>>temp.b>>temp.w;
        ar.push_back(temp);
    }
    sort(ar.begin(),ar.end(),comp);
    ll sum=0;
    int edges=0;
    for(edge e:ar){
        if(merge(e.a,e.b)){
            sum+=e.w;
            edges++;
        }
    }
    if(edges==n-1){
        cout<<sum<<endl;
    }
    else{
        cout<<"IMPOSSIBLE"<<endl;
    }
}