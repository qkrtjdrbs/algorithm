#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, visited[1001][1001][2];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool Map[1001][1001];

void bfs(){
    queue<tuple<int, int, bool>> q;
    q.push({sx, sy, 0});
    visited[sx][sy][0] = 1;
    while(!q.empty()){
        int x, y, magic;
        tie(x, y, magic) = q.front();
        q.pop();
        if(x == ex && y == ey) break;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!magic){
                if(Map[nx][ny]) {
                    if(!visited[nx][ny][1]){
                        q.push({nx, ny, 1});
                        visited[nx][ny][1] = visited[x][y][0] + 1;
                    }
                } else { 
                    if(!visited[nx][ny][0]){      
                        q.push({nx, ny, 0}); 
                        visited[nx][ny][0] = visited[x][y][0] + 1;
                    }
                }
            } else {
                if(!Map[nx][ny] && !visited[nx][ny][1]){
                    q.push({nx, ny, 1});
                    visited[nx][ny][1] = visited[x][y][1] + 1;
                }
            }
        }
    }
    if(!visited[ex][ey][0] && !visited[ex][ey][1]) cout << -1;
    else if(!visited[ex][ey][0] || !visited[ex][ey][1]) cout << max(visited[ex][ey][0], visited[ex][ey][1])-1;
    else if(visited[ex][ey][0] && visited[ex][ey][1]) cout << min(visited[ex][ey][0], visited[ex][ey][1])-1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> sx >> sy >> ex >> ey;
    sx--, sy--, ex--, ey--;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    bfs();
}