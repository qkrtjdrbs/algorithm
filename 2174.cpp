#include <bits/stdc++.h>
using namespace std;

int n, m, robots, commands, visited[101][101][4];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};
tuple<int, int, int> robot[101];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> m >> n >> robots >> commands;
    for(int i=1;i<=robots;i++){
        int y, x, d; char dir;
        cin >> y >> x >> dir;
        if(dir == 'E') d = 0;
        else if(dir == 'S') d = 1;
        else if(dir == 'W') d = 2;
        else d = 3;
        visited[n-x][y-1][d] = i;
        robot[i] = {n-x, y-1, d};
    }
    for(int i=0;i<commands;i++){
        int idx, cnt; char op;
        int x, y, d;
        cin >> idx >> op >> cnt;
        tie(x, y, d) = robot[idx];
        visited[x][y][d] = 0;
        if(op == 'L'){
            cnt %= 4;
            for(int j=0;j<cnt;j++){
                d = (d == 0 ? 3 : d - 1);
            }
            visited[x][y][d] = idx;
            robot[idx] = {x, y, d};
        } else if(op == 'R') {
            cnt %= 4;
            for(int j=0;j<cnt;j++){
                d = (d == 3 ? 0 : d + 1);
            }
            visited[x][y][d] = idx;
            robot[idx] = {x, y, d};
        } else {
            for(int j=1;j<=cnt;j++){
                int nx = x + dx[d] * j;
                int ny = y + dy[d] * j;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                    cout << "Robot " << idx << " crashes into the wall";
                    return 0;
                }
                for(int k=0;k<4;k++){
                    if(visited[nx][ny][k]){
                        cout << "Robot " << idx << " crashes into robot " << visited[nx][ny][k];
                        return 0;
                    }
                }
            }
            int nx = x + dx[d] * cnt;
            int ny = y + dy[d] * cnt;
            visited[nx][ny][d] = idx;
            robot[idx] = {nx, ny, d};
        }
    }
    cout << "OK";
}