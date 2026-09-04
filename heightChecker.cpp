#include<bits/stdc++.h>
using namespace std;
int32_t main(){
	int height[];
	vector<int>v(height.begin(),height.end());
	sort(v.begin(),v.end());
	int cnt=0;
	for(int i=0;i<height.size();i++){
		if(height[i]!=v[i]){
			cnt++;
		}
	}
	return cnt;

}