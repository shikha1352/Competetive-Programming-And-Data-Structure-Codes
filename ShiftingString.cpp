#include<bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int a, int b){
  if(b==0) return a;
  return gcd(b,a%b);
}
int lcm(int a, int b) {
    return (a /gcd(a, b)) * b;
}
int32_t main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin>>t;
  while(t--)
  {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int>a(n+1);
        for(int i=0;i<n;i++){
          cin>>a[i];
        }
        vector<int>vis(n+1);
        int answer=1;
        for(int i=0;i<n;i++){
          if(vis[i])
            continue;
          string s2;
          for(int j=i+1;!vis[j-1];j=a[j-1]){
            vis[j-1]=1;
            s2+=s[j-1];
          }
          int c=(s2+s2).find(s2,1);
          answer=lcm(answer,c);
        }
        cout<<answer<<endl;
  }
  return 0;
}