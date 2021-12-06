#include <bits/stdc++.h>
using namespace std;

int n, lcow[1001], rcow[1001], dp[1001][1001];

int go(int l, int r){
    if(l >= n || r >= n) return 0;
    int &res = dp[l][r];
    if(res != -1) return res;
    res = 0;
    res = max({res, go(l+1, r), go(l, r+1)});
    int diff = abs(lcow[l] - rcow[r]);
    if(diff <= 4) res = max(res, 1+go(l+1, r+1));
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++) cin >> lcow[i];
    for(int i=0;i<n;i++) cin >> rcow[i];
    cout << go(0, 0);
}