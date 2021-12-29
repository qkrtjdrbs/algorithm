#include <bits/stdc++.h>
using namespace std;

int n, m, dp[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[51][51];
bool roof, processing[51][51];

int go(int x, int y){
    if(Map[x][y] == 'H') return 0;
    if(x < 0 || x >= n || y < 0 || y >= m) return 0;
    if(processing[x][y]){
        roof = true;
        return 0;
    }
    int &res = dp[x][y];
    if(res != -1) return res;
    processing[x][y] = 1;
    res = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i] * (Map[x][y]-'0');
        int ny = y + dy[i] * (Map[x][y]-'0');
        res = max(res, 1 + go(nx, ny));
    }
    processing[x][y] = 0;
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    int ans = go(0, 0);
    cout << (roof ? -1 : ans);
}