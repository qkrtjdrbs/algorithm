#include <bits/stdc++.h>
using namespace std;
int n, Map[500][500], ans, blowSand;
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

bool isOut(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= n) return true;
    return false;
}

void sandCal(float ratio, int x, int y, int i, int j){
    blowSand += Map[x][y] * (ratio / 100.0);
    if(isOut(i, j)){
        ans += Map[x][y] * (ratio / 100.0);
    } else {
        Map[i][j] += Map[x][y] * (ratio / 100.0);
    }
}

void spread(int x, int y, int dir){
    blowSand = 0;
    switch (dir)
    {
    case 0:
        for(int i=x-2;i<=x+2;i++){
            for(int j=y-2;j<=y+2;j++){
                if(j == y){
                    if(i == x-2 || i == x+2){
                        sandCal(2, x, y, i, j);
                    } else if(i == x-1 || i == x+1){
                        sandCal(7, x, y, i, j);
                    }
                } else if(j == y-1 && (i == x-1 || i == x+1)){
                    sandCal(10, x, y, i, j);
                } else if(j == y+1 && (i == x-1 || i == x+1)){
                    sandCal(1, x, y, i, j);
                } else if(j == y-2 && i == x){
                    sandCal(5, x, y, i, j);
                }
            }
        }
        if(isOut(x, y-1)){
            ans += Map[x][y] - blowSand;
        } else {
            Map[x][y-1] += Map[x][y] - blowSand;
        }
        Map[x][y] = 0;
    break;
    case 1:
        for(int i=x-2;i<=x+2;i++){
            for(int j=y-2;j<=y+2;j++){
                if(i == x){
                    if(j == y-2 || j == y+2){
                        sandCal(2, x, y, i, j);
                    } else if(j == y-1 || j == y+1){
                        sandCal(7, x, y, i, j);
                    }
                } else if(i == x+1 && (j == y-1 || j == y+1)){
                    sandCal(10, x, y, i, j);
                } else if(i == x-1 && (j == y-1 || j == y+1)){
                    sandCal(1, x, y, i, j);
                } else if(i == x+2 && j == y){
                    sandCal(5, x, y, i, j);
                }
            }
        }
        if(isOut(x+1, y)){
            ans += Map[x][y] - blowSand;
        } else {
            Map[x+1][y] += Map[x][y] - blowSand;
        }
        Map[x][y] = 0;
    break;
    case 2:
        for(int i=x-2;i<=x+2;i++){
            for(int j=y-2;j<=y+2;j++){
                if(j == y){
                    if(i == x-2 || i == x+2){
                        sandCal(2, x, y, i, j);
                    } else if(i == x-1 || i == x+1){
                        sandCal(7, x, y, i, j);
                    }
                } else if(j == y-1 && (i == x-1 || i == x+1)){
                    sandCal(1, x, y, i, j);
                } else if(j == y+1 && (i == x-1 || i == x+1)){
                    sandCal(10, x, y, i, j);
                } else if(j == y+2 && i == x){
                    sandCal(5, x, y, i, j);
                }
            }
        }
        if(isOut(x, y+1)){
            ans += Map[x][y] - blowSand;
        } else {
            Map[x][y+1] += Map[x][y] - blowSand;
        }
        Map[x][y] = 0;
    break;
    case 3:
         for(int i=x-2;i<=x+2;i++){
            for(int j=y-2;j<=y+2;j++){
                if(i == x){
                    if(j == y-2 || j == y+2){
                        sandCal(2, x, y, i, j);
                    } else if(j == y-1 || j == y+1){
                        sandCal(7, x, y, i, j);
                    }
                } else if(i == x+1 && (j == y-1 || j == y+1)){
                    sandCal(1, x, y, i, j);
                } else if(i == x-1 && (j == y-1 || j == y+1)){
                    sandCal(10, x, y, i, j);
                } else if(i == x-2 && j == y){
                    sandCal(5, x, y, i, j);
                }
            }
        }
        if(isOut(x-1, y)){
            ans += Map[x][y] - blowSand;
        } else {
            Map[x-1][y] += Map[x][y] - blowSand;
        }
        Map[x][y] = 0;
    break;
    }
}

void tornado(int x, int y, int cnt, int maxCnt, int dirChange, int dir){
    if(x == 0 && y == -1) return;
    if(Map[x][y])
        spread(x, y, dir);
    int nx, ny, nd;
    if(cnt == maxCnt){
        dir == 3 ? nd = 0 : nd = dir + 1;
        nx = x + dx[nd];
        ny = y + dy[nd];
        if(dirChange == 1){
            tornado(nx, ny, 1, maxCnt+1, 0, nd);
        } else {
            tornado(nx, ny, 1, maxCnt, dirChange+1, nd);
        }
    } else {
        nx = x + dx[dir];
        ny = y + dy[dir];
        tornado(nx, ny, cnt+1, maxCnt, dirChange, dir);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> Map[i][j];
    }
    int startX = n/2, startY = n/2;
    tornado(startX, startY, 0, 1, 0, 0);
    cout << ans;
}