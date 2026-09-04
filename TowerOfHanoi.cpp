#include<bits/stdc++.h>
using namespace std;
void tower(int n,int a,int b,int c){
    if(n==0)
    return;
    tower(n-1,a,c,b);
    cout<<a<<" "<<c<<endl;
    tower(n-1,b,a,c);
}
void solve(){
    int n;
    cin>>n;
    cout<<(1<<n)-1<<endl;
    tower(n,1,2,3);
}
int main(){
    solve();
}