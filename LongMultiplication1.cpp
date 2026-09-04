#include <bits/stdc++.h>
using namespace std;
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1;
        string s2;
        cin >> s1 >> s2;
        string x,y;
        int tg=0;
        for(int i=0;i<s1.size();i++){
            if(tg==0){
                if(s1[i]==s2[i]){
                    x+=s1[i];
                    y+=s2[i];
                }
                else if(s1[i]>s2[i]){
                    tg=1;
                    x+=s1[i];
                    y+=s2[i];
                }
                else{
                    tg=1;
                    x+=s2[i];
                    y+=s1[i];
                }
            }
            else{
                if(s1[i]>s2[i]){
                    x+=s2[i];
                    y+=s1[i];
                }
                else{
                    x+=s1[i];
                    y+=s2[i];
                }
            }
        }
        cout<<x<<endl<<y<<endl;
    }
}