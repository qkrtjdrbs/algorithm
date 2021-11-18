#include <bits/stdc++.h>
using namespace std;

int n, L, R, X, ans, arr[16];

void go(int idx, int sum, int mn, int mx){
    if(idx == n){
        if(L <= sum && sum <= R && mx - mn >= X) ans++;
        return;
    }
    go(idx+1, sum+arr[idx], min(mn, arr[idx]), max(mx, arr[idx]));
    go(idx+1, sum, mn, mx);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> L >> R >> X;
    int sum = 0;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    go(0, 0, 987654321, 0);
    cout << ans;
}