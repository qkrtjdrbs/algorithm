#include <bits/stdc++.h>
using namespace std;

int n, m, Map[1001][1001], dp[1001][1001][3];
int dx[] = {0,0,1};
int dy[] = {-1,1,0};

int go(int x, int y, int d, int px, int py){
    if(x == n-1 && y == m-1) return Map[x][y];
    int &res = dp[x][y][d];
    if(res != -1) return res;
    res = -1e9;
    for(int i=0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(nx == px && ny == py) continue;
        res = max(res, go(nx, ny, i, x, y));
    }
    res += Map[x][y];
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    cout << go(0, 0, 0, -1, -1);
}