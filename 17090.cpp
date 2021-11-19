#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[505][505];
bool visited[505][505];

bool check(int x, int y, int dir){
    if(dir == 0 && Map[x][y] == 'R') return true;
    if(dir == 1 && Map[x][y] == 'L') return true;
    if(dir == 2 && Map[x][y] == 'D') return true;
    if(dir == 3 && Map[x][y] == 'U') return true;
    return false;
}

void bfs(){
    queue<pair<int, int>> q;
    for(int i=1;i<=m;i++){
        if(Map[1][i] == 'U'){
            q.push({1, i});
            visited[1][i] = 1;
        }
        if(Map[n][i] == 'D'){
            q.push({n, i});
            visited[n][i] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        if(Map[i][1] == 'L'){
            q.push({i, 1});
            visited[i][1] = 1;
        }
        if(Map[i][m] == 'R'){
            q.push({i, m});
            visited[i][m] = 1;
        }
    }
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
            if(visited[nx][ny]) continue;
            if(check(nx, ny, i)){
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) cin >> Map[i][j];
    }
    bfs();
    int ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(visited[i][j]) ans++;
        }
    }
    cout << ans;
}