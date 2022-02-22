#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, sxx, syy, Map[1001][1001], visited[1001][1001][3], cnt[4];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 1}); visited[sx][sy][1] = 1; visited[sx][sy][0] = 1;
    q.push({sxx, syy, 2}); visited[sxx][syy][2] = 1; visited[sxx][syy][0] = 2;
    while(!q.empty()){
        auto [x, y, z] = q.front();
        q.pop();
        if(visited[x][y][0] == 3) continue;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int opz = z == 1 ? 2 : 1;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] == -1 || visited[nx][ny][z]) continue;
            if(visited[nx][ny][opz] && visited[nx][ny][opz] < visited[x][y][z] + 1) continue;
            if(visited[nx][ny][opz] == visited[x][y][z] + 1){
                visited[nx][ny][0] = 3;
                continue;
            }
            q.push({nx, ny, z});
            visited[nx][ny][z] = visited[x][y][z] + 1;
            visited[nx][ny][0] = z;
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 1){
                sx = i; sy = j;
            } else if(Map[i][j] == 2){
                sxx = i; syy = j;
            }
        }
    }
    bfs();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cnt[visited[i][j][0]]++;
        }
    }
    cout << cnt[1] << " " << cnt[2] << " " << cnt[3];
}