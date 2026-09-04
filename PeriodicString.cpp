#include<bits/stdc++.h>
using namespace std;
vector<int>lps;
void computeLPSArray(string pat, int M){
	int len = 0;
	lps[0] = 0;

 	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else {
			if (len != 0) {
				len = lps[len - 1];
			}
			else {
				lps[i] = 0;
				i++;
			}
		}
	}
}
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        int m=s.size();lps.resize(m);
        computeLPSArray(s,m);
        int l=lps[m-1];
        int period=m-l;
        if(m%period==0){
        cout<<period<<endl;
        }
        else{
            cout<<m<<endl;
        }
        if(t){
            cout<<endl;
        }
    }
}