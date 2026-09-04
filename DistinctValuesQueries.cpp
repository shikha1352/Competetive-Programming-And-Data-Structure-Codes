#include <bits/stdc++.h>
using namespace std;
const int BLOCK = 1000;
struct query {
    int l, r, i;
};

bool comp(query a, query b) {
    if (a.l / BLOCK != b.l / BLOCK)
        return a.l / BLOCK < b.l / BLOCK;
    return a.r < b.r;
}

void add(int pos, vector<int>& ar, vector<int>& fre, int& cnt) {
    fre[ar[pos]]++;
    if (fre[ar[pos]] == 1)
        cnt++;
}

void remove(int pos, vector<int>& ar, vector<int>& fre, int& cnt) {
    fre[ar[pos]]--;
    if (fre[ar[pos]] == 0)
        cnt--;
}
int main() {
    int n, q;
    cin >> n >> q;
    vector<int> ar(n);
    map<int,int> coordinateCompress;
   int compressed_Num = 1;

   for(int i = 0; i < n; i++)
   {
       cin >> ar[i];
       if(coordinateCompress.find(ar[i]) != coordinateCompress.end()){
        ar[i] = coordinateCompress[ar[i]];
       }
       else{
        coordinateCompress[ar[i]] = compressed_Num;
        ar[i] = compressed_Num++;
       }
   }

    vector<query> Q(q);
    for (int i = 0; i < q; i++) {
        cin >> Q[i].l >> Q[i].r;
        Q[i].i = i;
        Q[i].l--;  
        Q[i].r--;  
    }

    sort(Q.begin(), Q.end(), comp);

    vector<int> ans(q);
    vector<int> fre(1000001, 0);  
    int cnt = 0;
    int ml = 0, mr = -1;

    for (int i = 0; i < q; i++) {
        int L = Q[i].l;
        int R = Q[i].r;

        while (mr < R) {
            mr++;
            add(mr, ar, fre, cnt);
        }
        while (mr > R) {
            remove(mr, ar, fre, cnt);
            mr--;
        }
        while (ml < L) {
            remove(ml, ar, fre, cnt);
            ml++;
        }
        while (ml > L) {
            ml--;
            add(ml, ar, fre, cnt);
        }

        ans[Q[i].i] = cnt;
    }

    for (int i = 0; i < q; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}
