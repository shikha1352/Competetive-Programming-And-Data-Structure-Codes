#include<bits/stdc++.h>
using namespace std;
const int N=1e8;
vector<bool>seive(N+1,true);
vector<int>prime;
void generate_seive(){
    seive[0]=false;
    seive[1]=false;
    for(int i=2;i*i<=N;i++){
        if(seive[i]){
        for(int j=i*i;j<=N;j+=i){
            {
                seive[j]=false;
            }
        }
        }
    }
    
    for(int i=2;i<=N;i++){
        if(seive[i]){
            prime.push_back(i);
        }
    }
}
void solve(){
    for(int i=1;i<prime.size();i+=100){
        cout<<prime[i-1]<<endl;
    }
}
int32_t main(){
    generate_seive();
    solve();

}