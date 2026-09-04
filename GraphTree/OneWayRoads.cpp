#include<bits/stdc++.h>
using namespace std;
#define size 105
bool visited1[size];
bool visited2[size];
int w1;
int w2;
int main(){
        int n;
        cin>>n;
        w1=0,w2=0;
        memset(visited1, 0, sizeof visited1);
		memset(visited2, 0, sizeof visited2);
        int a,b,c;
        for(int j = 0; j < n; j++)
		{
			cin>>a>>b>>c;
			if(!visited1[a] && !visited2[b])
			{
				visited1[a] = visited2[b] = true;
				w1 += c;
			}
			
			else
			{
				visited2[a] = visited1[b] = true;
			   w2 += c;
			}
		}
        int d=min(w1,w2);
         cout<<d<<endl;
}

