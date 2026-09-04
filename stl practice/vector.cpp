#include<bits/stdc++.h>
using namespace std;
void printvec(vector<string>v){
    cout<<"size:"<<v.size()<<endl;
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main()
{
     vector<string>v;
     /*int n;
     cin>>n;
     for(int i=0;i<n;i++){
        int x;
        cin>>x;
         printvec(v);
        v.push_back(x);
     }
     printvec(v);*/

   /*v.push_back(7);
    v.push_back(6);
     printvec(v);
     v.pop_back();
     printvec(v);
     vector<int>&v2=v;
     v2.push_back(5);
     printvec(v);
     printvec(v2);*/
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    printvec(v);
}