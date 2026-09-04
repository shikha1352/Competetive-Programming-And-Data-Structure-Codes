#include<bits/stdc++.h>
using namespace std;
int calculate(int x){
	int score=0;iwhile(x>1){
		score++;
		x/=2;
	}
	return score;
}
int32_t main(){
	int t;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		int cnt=calculate(r);
		cout<<cnt<<endl;
	}
}