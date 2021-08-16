#include <bits/stdc++.h>
using namespace std;

enum {
    U = 1,
    D = 2,
    L = 3,
    R = 4,
    T = 5,
};

typedef struct wood {
    int x, y;
}Wood;

int n, ans, Visit[51][51][2]; //visit은 가운데 통나무 기준, 마지막 0은 가로, 1은 세로
string Map[51];
Wood wood[3];

bool isRotateOk(int x, int y){
    for(int i=x-1;i<=x+1;i++){
        for(int j=y-1;j<=y+1;j++){
            if(i < 0 || i >= n || j < 0 || j >= n){
                return false;
            }
            if(Map[i][j] == '1') return false;
        }
    }
    return true;
}

int shape(int x, int y){
    if(wood[0].x == x) return 0;
    return 1;
}

bool isFit(int x, int y, int s){
    if(s == 0){
        if(y-1 < 0 || y-1 >= n || y+1 < 0 || y+1 >= n) return false;
        return Map[x][y-1] == 'E' && Map[x][y] == 'E' && Map[x][y+1] == 'E';
    } else {
        if(x-1 < 0 || x-1 >= n || x+1 < 0 || x+1 >= n) return false;
        return Map[x-1][y] == 'E' && Map[x][y] == 'E' && Map[x+1][y] == 'E';
    }
}

bool noBlock(int x, int y, int s){
    if(s == 0)
        return Map[x][y-1] != '1' && Map[x][y] != '1' && Map[x][y+1] != '1';
    return Map[x-1][y] != '1' && Map[x][y] != '1' && Map[x+1][y] != '1';
}

void bfs(){
    //x, y, s
    queue<tuple<int, int, int>> q;
    q.push({wood[1].x, wood[1].y, shape(wood[1].x, wood[1].y)});
    while(!q.empty()){
        int x, y, s;
        tie(x, y, s) = q.front();
        q.pop();
        if(isFit(x, y, s)){
            ans = Visit[x][y][s]-1;
            break;
        }
        if(s == 0){
            int nx = x - 1;            
            int ny = y;
            if(0 <= nx && !Visit[nx][ny][s] && noBlock(nx, ny, 0)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            nx = x + 1;
            if(nx < n && !Visit[nx][ny][s] && noBlock(nx, ny, 0)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            nx = x;
            ny = y - 1;
            if(0 <= ny-1 && !Visit[nx][ny][s] && noBlock(nx, ny, 0)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            ny = y + 1;
            if(ny+1 < n && !Visit[nx][ny][s] && noBlock(nx, ny, 0)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            if(!Visit[x][y][!s] && isRotateOk(x, y)){
                Visit[x][y][!s] = Visit[x][y][s] + 1;
                q.push({x, y, !s});
            }            
        } else {
            int nx = x - 1;            
            int ny = y;
            if(0 <= nx-1 && !Visit[nx][ny][s] && noBlock(nx, ny, 1)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            nx = x + 1;
            if(nx+1 < n && !Visit[nx][ny][s] && noBlock(nx, ny, 1)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            nx = x;
            ny = y - 1;
            if(0 <= ny && !Visit[nx][ny][s] && noBlock(nx, ny, 1)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            ny = y + 1;
            if(ny < n && !Visit[nx][ny][s] && noBlock(nx, ny, 1)){
                Visit[nx][ny][s] = Visit[x][y][s] + 1;
                q.push({nx, ny, s});
            }
            if(!Visit[x][y][!s] && isRotateOk(x, y)){
                Visit[x][y][!s] = Visit[x][y][s] + 1;
                q.push({x, y, !s});
            }  
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> Map[i];
    int idx = 0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++){
            if(Map[i][j] == 'B') {
                if(idx == 1) Visit[i][j][shape(i, j)] = 1;
                wood[idx++] = {i, j};              
            }
        }
    bfs();
    cout << ans;
    return 0;
}