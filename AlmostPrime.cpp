#include<bits/stdc++.h>
using namespace std;
const int N=3000;
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
void solve(int n){
    int cnt=0;
   
    vector<int>ans;
    for(int i=3;i<=n;i++){
        for(int j=0;j<prime.size();j++){
            if(i%prime[j]==0){
                cnt++;
                
            }
        }
        if(cnt==2){
            ans.push_back(i);
        }
        cnt=0;
    }
    cout<<ans.size()<<endl;
    
}
int32_t main(){
    generate_seive();
    int n;
    cin>>n;
    solve(n);

}