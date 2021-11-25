#include <bits/stdc++.h>
using namespace std;

int n, cost[16][16], dp[16][10][1 << 17];

int go(int cur, int c, int bits){
    int &res = dp[cur][c][bits];
    if(res != -1) return res;
    res = 1;
    for(int i=0;i<n;i++){
        if((bits & (1 << i)) || cur == i) continue;
        if(cost[cur][i] >= c){
            res = max(res, 1 + go(i, cost[cur][i], (bits | (1 << i))));
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<n;j++){
            int c = tmp[j] - '0';
            cost[i][j] = c;
        }
    }
    cout << go(0, 0, 1);
}