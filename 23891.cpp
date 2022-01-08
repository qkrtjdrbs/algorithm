#include <bits/stdc++.h>
using namespace std;

int n, m, sum, dp[101][100001], score[101], p[101];

int go(int idx, int rest){
    if(idx == n) return 0;
    int &res = dp[idx][rest];
    if(res != -1) return res;

    res = max(res, go(idx+1, rest));
    if(rest > p[idx]){
        res = max({res, 2*score[idx]+go(idx+1, rest-(p[idx]+1)), score[idx]+go(idx+1, rest-p[idx])});
    }
    if(rest == p[idx]){
        res = max(res, score[idx]+go(idx+1, rest-p[idx]));
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> score[i] >> p[i];
        sum += score[i];
    }
    memset(dp, -1 , sizeof(dp));
    int res = go(0, m);
    if(res > sum) cout << 'W';
    else if(res < sum) cout << 'L';
    else cout << 'D';
}