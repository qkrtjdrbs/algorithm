#include <bits/stdc++.h>
using namespace std;

int n, m, k, Map[21][21], color[21][21], cnt[501];
int dice[7] = {0,1,2,3,4,5,6};
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

tuple<int, int, int> roll(int x, int y, int d){
    int nx = x + dx[d]; 
    int ny = y + dy[d];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m){
        d = (d+2) % 4;
        nx = x + dx[d];
        ny = y + dy[d];
    }
    int tmp[7]; memcpy(tmp, dice, sizeof(dice));
    if(d == 0){
        tmp[1] = dice[4]; tmp[3] = dice[1]; tmp[4] = dice[6]; tmp[6] = dice[3];
    } else if(d == 1){
        tmp[1] = dice[2]; tmp[2] = dice[6]; tmp[5] = dice[1]; tmp[6] = dice[5];
    } else if(d == 2){
        tmp[1] = dice[3]; tmp[3] = dice[6]; tmp[4] = dice[1]; tmp[6] = dice[4];
    } else {
        tmp[1] = dice[5]; tmp[2] = dice[1]; tmp[5] = dice[6]; tmp[6] = dice[2];
    }
    memcpy(dice, tmp, sizeof(tmp));
    if(dice[6] > Map[nx][ny]) d = d == 3 ? 0 : d + 1;
    else if(dice[6] < Map[nx][ny]) d = d == 0 ? 3 : d - 1;
    return {nx, ny, d};
}

int coloring(int x, int y, int c){
    color[x][y] = c;
    int res = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m ) continue;
        if(color[nx][ny] || Map[x][y] != Map[nx][ny]) continue;
        res += 1 + coloring(nx, ny, c);
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    int idx = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!color[i][j]){
                cnt[idx] = 1 + coloring(i, j, idx);
                idx++;
            }
        }
    }
    int score = 0, dir = 0, x = 0, y = 0;
    for(int i=0;i<k;i++){
        tie(x, y, dir) = roll(x, y, dir);
        score += (cnt[color[x][y]] * Map[x][y]);
    }
    cout << score;
}