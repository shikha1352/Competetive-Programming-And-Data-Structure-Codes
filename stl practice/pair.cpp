#include<bits/stdc++.h>
using namespace std;
int main()
{
   
   /* p=make_pair(2,"abc");
   p={2,"abc"}; 
   pair<int,string>&p1=p;
   p1.first=3;
    cout<<p1.first<<" "<<p1.second<<endl;
    int a[]={1,2,3};
    int b[]={2,3,4};
    pair<int,int>p_array[3];
    p_array[0]={1,2};
    p_array[1]={2,3};
    p_array[2]={3,4};
    swap(p_array[0],p_array[2]);
    for(int i=0;i<3;i++)
    {
        cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }*/
     pair<int,string>p[4];
     for(int i=0;i<4;i++)
     {
         int x;
       string s;
        cin>>x;
        cin>>s;
        p[i]=make_pair(x,s);
       
     }
     for(int i=0;i<4;i++){
         cout<<p[i].first<<" "<<p[i].second<<endl;
     }
    // p=make_pair(1,"shikha");
    // p=make_pair(2,"mimi");
    // for(int i=0;i<2;i++){
    //     cout<<p.first<<" "<<p.second<<endl;
    // }
    pair<int,int>p_array[3];
    for(int i=0;i<3;i++){
        int x,y;
        cin>>x>>y;
        p_array[i]=make_pair(x,y);
    }
    for(int i=0;i<3;i++){
         cout<<p_array[i].first<<" "<<p_array[i].second<<endl;
    }
    cout<<endl;
}
