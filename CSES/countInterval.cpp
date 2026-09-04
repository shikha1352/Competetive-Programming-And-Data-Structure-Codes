#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        long long int l, r, cnt = 0;
        cin >> n >> l >> r;
        if(l==1){
                l++;
            }
            int mx=r-l+1;
            int arr[mx+1];
            for(int i=0;i<=mx;i++){
                arr[i]=0;
            }
            int x;
        for(int j = 0; j< n; j++){
            
            cin >> x;
            
                int i=(l/x)*x;
                if(i<l){
                    i+=x;
                }
                for(;i<=r;i+=x){
                    if(i%x==0){
                    if(arr[i-l]==0){
                        cnt++;
                        arr[i-l]=1;
                    }
                }
            }
    }
    cout << cnt << endl;
    
}
return 0;
}