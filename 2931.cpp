#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, hx, hy;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[26][26];
char Map[26][26];

pair<int, int> findHole(){
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if(Map[nx][ny] == '.'){
                if(Map[x][y] == '|' && (i == 2 || i == 3))  return {nx, ny};
                else if(Map[x][y] == '-' && (i == 0 || i == 1)) return {nx, ny};
                else if(Map[x][y] == '+') return {nx, ny};
                else if(Map[x][y] == '1' && (i == 1 || i == 3)) return {nx, ny};
                else if(Map[x][y] == '2' && (i == 1 || i == 2)) return {nx, ny};
                else if(Map[x][y] == '3' && (i == 0 || i == 2)) return {nx, ny};
                else if(Map[x][y] == '4' && (i == 0 || i == 3)) return {nx, ny};
            } else {
                q.push({nx, ny});
                visited[nx][ny] = 1;
            }
        }
    }
    return {-1, -1};
}

void fillHole(){
    bool dir[4] = {0,};
    for(int i=0;i<4;i++){
        int nx = hx + dx[i];
        int ny = hy + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(Map[nx][ny] != '.'){
            if(Map[nx][ny] == '|' && (i == 0 || i == 1)) continue;
            else if(Map[nx][ny] == '-' && (i == 2 || i == 3)) continue;
            else if(Map[nx][ny] == '1' && (i == 1 || i == 3)) continue;
            else if(Map[nx][ny] == '2' && (i == 1 || i == 2)) continue;
            else if(Map[nx][ny] == '3' && (i == 0 || i == 2)) continue;
            else if(Map[nx][ny] == '4' && (i == 0 || i == 3)) continue;
            else if(Map[nx][ny] == 'M') continue;
            else if(Map[nx][ny] == 'Z') continue;
            dir[i] = 1;
        }
    }
    if(dir[0] && dir[1]){
        if(dir[2] && dir[3]) cout << '+';
        else cout << '-';
    } else if(!dir[0] && !dir[1] && dir[2] && dir[3]) cout << '|';
    else if(dir[1] && dir[3]) cout << '1';
    else if(dir[1] && dir[2]) cout << '2';
    else if(dir[0] && dir[2]) cout << '3';
    else if(dir[0] && dir[3]) cout << '4';
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) {
            cin >> Map[i][j];
            if(Map[i][j] == 'M'){
                sx = i; sy = j;
            }
            if(Map[i][j] == 'Z'){
                ex = i; ey = j;
            }
        }
    }
    tie(hx, hy) = findHole();
    cout << hx+1 << " " << hy+1 << " ";
    fillHole();
}