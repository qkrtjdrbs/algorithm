#include <bits/stdc++.h>
using namespace std;

int n, m, a[1501][1501], b[1501][1501], dp[1501][1501];

int go(int x, int y){
    if(x == n && y == m) return 0;
    int &res = dp[x][y];
    if(res != -1) return res;
    if(x+1 <= n) res = max(res, go(x+1, y)+a[x+1][y-1]);
    if(x+1 <= n && y+1 <= m) res = max(res, go(x+1, y+1)+a[x+1][y]+b[x][y+1]);
    if(y+1 <= m) res = max(res, go(x, y+1)+b[x-1][y+1]);
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            string x, fruit; int cnt;
            cin >> x;
            fruit = x.substr(0, 1);
            cnt = stoi(x.substr(1));
            a[i][j] += a[i][j-1]; 
            b[i][j] += b[i-1][j];
            if(fruit == "A") a[i][j] += cnt;
            else b[i][j] += cnt;
        }
    }
    cout << go(1, 1);
}