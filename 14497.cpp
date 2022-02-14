#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, visited[301][301];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[301][301];
queue<pair<int, int>> q;

void go(int x, int y, int cnt){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
        if(visited[nx][ny]) continue;
        visited[nx][ny] = cnt;
        if(Map[nx][ny] == '0'){
            go(nx, ny, cnt);
        } else if(Map[nx][ny] == '#'){
            return;
        } else {
            q.push({nx, ny});
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> sx >> sy >> ex >> ey;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> Map[i][j];
    }
    visited[sx][sy] = 1;
    go(sx, sy, 1);
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        go(x, y, visited[x][y]+1);
    }
    cout << visited[ex][ey];
}