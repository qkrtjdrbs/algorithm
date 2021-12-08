#include <bits/stdc++.h>
using namespace std;

int n, m, visited[3001][3001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[3001][3001];

void bfs(int sx, int sy){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] == '1' || visited[nx][ny]) continue;
            if(Map[nx][ny] == '0'){
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            } else {
                cout << "TAK" << '\n';
                cout << visited[x][y];
                return;
            }
        }
    }
    cout << "NIE";
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    int sx, sy;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == '2'){
                sx = i; sy = j;
            }
        }
    }
    bfs(sx, sy);
}