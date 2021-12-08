#include <bits/stdc++.h>
using namespace std;

int n, m, dp[1001][1001][2];
int dx[] = {0,1,-1};
int dy[] = {1,1,1};
char Map[1001][1001];

int go(int x, int y, bool e){
    if(e) return 987654321;
    int &res = dp[x][y][e];
    if(res != -1) return res;
    res = 0;
    for(int i=0;i<3;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(Map[nx][ny] == '#') continue;
        if(Map[nx][ny] == 'C'){
            res = max(res, 1+go(nx, ny, e));
        } else if(Map[nx][ny] == '.'){
            res = max(res, go(nx, ny, e));
        } else {
            res = max({res, go(nx, ny, 0),  go(nx, ny, 1)});
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1 ,sizeof(dp));
    cin >> n >> m;
    int sx, sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'R'){
                sx = i; sy = j;
            }
        }
    }
    int ans = go(sx, sy, 0) - 987654321;
    ans < 0 ? cout << -1 : cout << ans;
}