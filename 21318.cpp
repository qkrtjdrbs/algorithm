#include <bits/stdc++.h>
using namespace std;

int n, q, dfct[100002], psum[100002];
bool check[100002];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++) cin >> dfct[i];
    for(int i=1;i<n;i++){
        if(dfct[i] > dfct[i+1]) {
            psum[i] = 1;
            check[i] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        psum[i] += psum[i-1];
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int x, y;
        cin >> x >> y;
        cout << psum[y] - psum[x-1] - check[y] << '\n';
    }
}