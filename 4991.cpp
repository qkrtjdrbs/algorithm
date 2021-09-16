#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    while(1){
        int sx, sy, n, m, dtNum[21][21], visited[21][21][1 << 10], num=0;
        char Map[21][21];
        memset(visited, 0, sizeof(visited));
        cin >> m >> n;
        if(!n && !m) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> Map[i][j];
                if(Map[i][j] == 'o'){
                    sx = i;
                    sy = j;
                } else if(Map[i][j] == '*'){
                    dtNum[i][j] = num++;
                }
            }
        }
        queue<tuple<int, int, int>> q;
        q.push({sx, sy, 1 << num});
        visited[sx][sy][1 << num] = 1;
        while(!q.empty()){
            int x, y, state;
            tie(x, y, state) = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || Map[nx][ny] == 'x') continue;
                if(Map[nx][ny] == '*'){
                    if(!visited[nx][ny][state | (1 << dtNum[nx][ny])]){
                        visited[nx][ny][state | (1 << dtNum[nx][ny])] = visited[x][y][state] + 1;
                        q.push({nx, ny, state | (1 << dtNum[nx][ny])});
                    }
                } else {
                    if(!visited[nx][ny][state]){
                        visited[nx][ny][state] = visited[x][y][state] + 1;
                        q.push({nx, ny, state});
                    }
                }
            }
        }
        int ans = 987654321;
        int allClean = (1 << num+1)-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j][allClean]){
                    ans = min(ans, visited[i][j][allClean]);
                }
            }
        }
        ans == 987654321 ? cout << -1 : cout << ans-1;
        cout << '\n';
    }
}