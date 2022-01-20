#include <bits/stdc++.h>
using namespace std;

int n, m, c[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int, int>> v;
char Map[51][51];

int bfs(int sx, int sy){
    int visited[51][51][4][1 << 3];
    memset(visited, 0, sizeof(visited));
    queue<tuple<int, int, int, int>> q;
    q.push({sx, sy, 0, 0}); visited[sx][sy][0][0] = 1;
    q.push({sx, sy, 1, 0}); visited[sx][sy][1][0] = 1;
    q.push({sx, sy, 2, 0}); visited[sx][sy][2][0] = 1;
    q.push({sx, sy, 3, 0}); visited[sx][sy][3][0] = 1;
    while(!q.empty()){
        int x, y, dir, del;
        tie(x, y, dir, del) = q.front();
        q.pop();
        if((del & (1 << 0)) && (del & (1 << 1))) return visited[x][y][dir][del] - 1;
        for(int i=0;i<4;i++){
            if(dir == i) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] == '#') continue;
            if(Map[nx][ny] == 'C'){
                int ndel = del | (1 << c[nx][ny]);
                if(visited[nx][ny][i][ndel]) continue;
                visited[nx][ny][i][ndel] = visited[x][y][dir][del] + 1;
                q.push({nx, ny, i, ndel});
            } else if(Map[nx][ny] == '.' || Map[nx][ny] == 'S'){
                if(visited[nx][ny][i][del]) continue;
                visited[nx][ny][i][del] = visited[x][y][dir][del] + 1;
                q.push({nx, ny, i, del});
            }
        }
    }
    return 987654321;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    int sx, sy, cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'S'){
                sx = i; sy = j;
            } else if(Map[i][j] == 'C'){
                v.push_back({i, j});
                c[i][j] = cnt++;
            }
        }
    }
    int ans = bfs(sx, sy);
    cout << (ans == 987654321 ? -1 : ans);
}