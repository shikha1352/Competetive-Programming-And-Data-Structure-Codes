#include<bits/stdc++.h>
using namespace std;
void power(long long n,long long base){
     int result=1;
     while(n){
        if(n%2==1){
            result=(result*base)%10;
            n--;
        }
        else{
            base=(base*base)%10;
            n/=2;
        }
     }
     int d=result%10;
     cout<<d<<endl;
}
int main(){
    long long  n;
    cin>>n;
    long long base=8;
    power(n,base);
}