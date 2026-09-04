#include<bits/stdc++.h>
using namespace std;
void NGE(vector<int>v){
    vector<int>nge;
    stack<int>st;
    for(int i=0;i<v.size();i++){
        while(!st.empty() && v[i]>v[st.top()]){
            nge[st.top()]=i;
            st.pop();
        }
        st.push(i);
        while(!st.empty()){
            nge[st.top()]=-1;
            st.pop();
        }
    }
    
    for(int i=0;i<v.size();i++){
        if(nge[i]==-1)
        {
            cout<<"-1"<<" ";
        }
        else{
            cout<<v[nge[i]]<<" ";
        }
    }
    cout<<endl;
}
int main()
{
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    NGE(v);
}