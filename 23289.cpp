#include <bits/stdc++.h>
using namespace std;

int n, m, k, w, temp[21][21];
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};
int incX[5][3] = {{0,0,0},{-1,0,1},{-1,0,1},{-1,-1,-1},{1,1,1}};
int incY[5][3] = {{0,0,0},{1,1,1},{-1,-1,-1},{-1,0,1},{-1,0,1}};
int mx[5][3] = {{0,0,0},{-1,0,1},{-1,0,1},{0,-1,0},{0,1,0}};
int my[5][3] = {{0,0,0},{0,1,0},{0,-1,0},{-1,0,1},{-1,0,1}};
bool wall[21][21][21][21];
vector<pair<int, int>> confirm;
vector<tuple<int, int, int>> rooms;

bool canSpread(int x, int y, int dir, int c){
    int tx = x + mx[dir][c], ty = y + my[dir][c];
    int nx = x + incX[dir][c], ny = y + incY[dir][c];
    if(!wall[x][y][tx][ty] && !wall[tx][ty][nx][ny]) return true;
    return false;
}

void wind(){
    int tmp[21][21];
    bool visited[21][21];
    memcpy(tmp, temp, sizeof(temp));
    for(auto room : rooms){
        int i, j, idx;
        tie(i, j, idx) = room;
        memset(visited, 0, sizeof(visited));
        int dir = idx;
        int x = i + dx[dir], y = j + dy[dir]; 
        queue<tuple<int, int, int>> q;
        q.push({x, y, 5});
        tmp[x][y] += 5;
        while(!q.empty()){
            int inc;
            tie(x, y, inc) = q.front();
            q.pop();
            if(inc == 1) break;
            for(int c=0;c<3;c++){
                int nx = x + incX[dir][c];
                int ny = y + incY[dir][c];
                if(nx <= 0 || nx > n || ny <= 0 || ny > m || visited[nx][ny]) continue;
                if(!canSpread(x, y, dir, c)) continue;
                q.push({nx, ny, inc-1});
                visited[nx][ny] = 1;
                tmp[nx][ny] += inc-1;
            }
        } 
    }   
    memcpy(temp, tmp, sizeof(tmp));
}

void temperatureChange(){
    int tmp[21][21];
    bool visited[21][21];
    memset(visited, 0, sizeof(visited));
    memcpy(tmp, temp, sizeof(temp));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            visited[i][j] = 1;
            for(int t=1;t<=4;t++){
                int nx = i + dx[t];
                int ny = j + dy[t];
                if(nx <= 0 || nx > n || ny <= 0 || ny > m) continue;
                if(wall[i][j][nx][ny] || visited[nx][ny]) continue;
                int diff = abs(temp[i][j]-temp[nx][ny]) / 4;
                if(temp[i][j] <= temp[nx][ny]){
                    tmp[i][j] += diff; tmp[nx][ny] -= diff;
                } else {
                    tmp[i][j] -= diff; tmp[nx][ny] += diff;
                }
            }
        }
    }
    memcpy(temp, tmp, sizeof(tmp));
}

void edgeDecrease(){
    for(int i=1;i<=m;i++){
        if(temp[1][i]) temp[1][i]--;   
        if(temp[n][i]) temp[n][i]--;   
    }
    for(int i=2;i<=n-1;i++){
        if(temp[i][1]) temp[i][1]--;
        if(temp[i][m]) temp[i][m]--;
    }
}

bool isEnded(){
    for(auto r : confirm){
        int x, y;
        tie(x, y) = r;
        if(temp[x][y] < k) return false;
    }
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int idx;
            cin >> idx;
            if(1 <= idx && idx <= 4) rooms.push_back({i, j, idx});
            else if(idx == 5) confirm.push_back({i, j});
        }
    }
    cin >> w;
    for(int i=0;i<w;i++){
        int x, y, t;
        cin >> x >> y >> t;
        if(t) {
            wall[x][y][x][y+1] = 1; wall[x][y+1][x][y] = 1; 
        } else {
            wall[x][y][x-1][y] = 1; wall[x-1][y][x][y] = 1; 
        }
    }
    int choco = 0;
    while(choco <= 100){
        wind();
        temperatureChange();
        edgeDecrease();
        choco++;
        if(isEnded()) break;
    }
    cout << choco;
}