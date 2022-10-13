#include <bits/stdc++.h>
using namespace std;

int n, m, d, k, x, y, Map[21][21], dice[]={1,2,4,3,5,6};
int dx[] = {0,-1,0,1};
int dy[] = {1,0,-1,0};
bool visited[21][21];

void opposite(){
    if(d == 0) d = 2;
    else if(d == 1) d = 3;
    else if(d == 2) d = 0;
    else d = 1;
}

void roll(){
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        opposite();
        x += dx[d];
        y += dy[d];
    } else {
        x = nx;
        y = ny;
    }
    int tmp[6];
    memcpy(tmp, dice, sizeof(dice));
    if(d == 0){
        tmp[3] = dice[0]; tmp[5] = dice[3]; tmp[2] = dice[5]; tmp[0] = dice[2];
    } else if(d == 2){
        tmp[2] = dice[0]; tmp[5] = dice[2]; tmp[3] = dice[5]; tmp[0] = dice[3];
    } else if(d == 3){
        tmp[4] = dice[0]; tmp[5] = dice[4]; tmp[1] = dice[5]; tmp[0] = dice[1];
    } else {
        tmp[1] = dice[0]; tmp[5] = dice[1]; tmp[4] = dice[5]; tmp[0] = dice[4];
    }
    memcpy(dice, tmp, sizeof(tmp));
}

void nextDir(){
    if(dice[5] > Map[x][y]){
        d = d == 0 ? 3 : d-1;
    } else if(dice[5] < Map[x][y]){
        d = d == 3 ? 0 : d+1;
    }
}

int dfs(int xx, int yy){
    int res = 0;
    for(int i=0;i<4;i++){
        int nx = xx + dx[i];
        int ny = yy + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited[nx][ny] || Map[nx][ny] != Map[x][y]) continue;
        visited[nx][ny] = 1;
        res += dfs(nx, ny) + 1;
    }
    return res;
}

int score(){
    memset(visited, 0, sizeof(visited));
    visited[x][y] = 1;
    return (dfs(x, y)+1)*Map[x][y];
}

int simulate(){
    roll();
    int res = score();
    nextDir();
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    int ans = 0;
    for(int i=0;i<k;i++){
        ans += simulate();
    }
    cout << ans;
}