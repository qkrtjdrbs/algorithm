#include <bits/stdc++.h>
using namespace std;

int n, m, Map[501][501], dp[501][501], ans[501][501];
int dx[] = {0,0,-1,1,-1,-1,1,1};
int dy[] = {-1,1,0,0,-1,1,-1,1};

int go(int x, int y){
    int &res = dp[x][y];
    if(res != -1) return res;
    int mn = Map[x][y], idx = -1;
    for(int i=0;i<8;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(Map[nx][ny] < Map[x][y] && mn > Map[nx][ny]){
            mn =  Map[nx][ny];
            idx = i;
        }
    }
    if(idx == -1){
        res = m * x + y;
    } else {
        res = go(x+dx[idx], y+dy[idx]);
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int num = go(i, j);
            ans[num / m][num % m]++;
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}