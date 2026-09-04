#include<bits/stdc++.h>
using namespace std;
int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        vector<int>ans;
        vector<int>a;
        bool flag=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(a.empty()){
                a.push_back(v[i]);
                ans.push_back(1);
            }
            else{
                if(flag){
                    if(v[i]<a.back()){
                        ans.push_back(0);
                    }
                    else{
                        if(v[i]>a[0])
                        ans.push_back(0);
                        else{
                            ans.push_back(1);
                            a.push_back(v[i]);
                        }
                    }

                }
                else{
                    if(v[i]>=a.back()){
                        ans.push_back(1);
                        a.push_back(v[i]);
                    }
                    else{
                        if(v[i]>a[0]){
                            ans.push_back(0);
                        }
                        else{
                            flag=1;
                            ans.push_back(1);
                            a.push_back(v[i]);
                        }
                    }
                }
            }
        }
        for(auto it:ans){
            cout<<it;
        }
        cout<<endl;
    }
}