#include <bits/stdc++.h>
#define MAX 5
using namespace std;

int k, ans;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool Map[6][6], visited[6][6];

bool check(){
    for(int i=1;i<=MAX;i++){
        for(int j=1;j<=MAX;j++){
            if(!Map[i][j] && !visited[i][j]){
                return false;
            }
        }
    }
    return true;
}

void dfsB(int x, int y, int c, int ac){
    if(x == MAX && y == MAX){
        if(ac == c){
            if(check()) ans++;
        }
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || nx > MAX || ny <= 0 || ny > MAX || Map[nx][ny]) continue;
        if(!visited[nx][ny]){
            visited[nx][ny] = 1;
            dfsB(nx, ny, c+1, ac);
            visited[nx][ny] = 0;
        }
    }
}

void dfsA(int x, int y, int c, int sx, int sy){
    if(x == 1 && y == 1){
        dfsB(sx, sy, 0, c);
        return;
    }
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx <= 0 || nx > MAX || ny <= 0 || ny > MAX || Map[nx][ny]) continue;
        if(!visited[nx][ny]){
            visited[nx][ny] = 1;
            dfsA(nx, ny, c+1, sx, sy);
            visited[nx][ny] = 0;
        }
    }
}

void go(int sx, int sy){
    if(sx == 1 && sy == 1) return;
    if(sx == MAX && sy == MAX) return;

    memset(visited, 0, sizeof(visited));
    visited[sx][sy] = 1;
    dfsA(sx, sy, 0, sx, sy);
    visited[sx][sy] = 0;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> k;
    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        Map[x][y] = 1;
    }
    for(int i=1;i<=MAX;i++){
        for(int j=1;j<=MAX;j++){
            if(!Map[i][j]){
                go(i, j);
            }
        }
    }
    cout << ans;
}