#include <bits/stdc++.h>
using namespace std;

int n, ans, pins;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[9][9];
bool pined[9][9];

bool canJump(int x, int y, int dir){
    if(x < 0 || x >= 5 || y < 0 || y >= 9) return false;
    if(Map[x][y] != 'o') return false;
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    if(nx < 0 || nx >= 5 || ny < 0 || ny >= 9) return false;
    if(Map[nx][ny] != '.') return false;
    return true;
}

void go(int cnt){
    if(cnt > 150) return;
    ans = max(ans, cnt);
      
    for(int i=0;i<5;i++){
        for(int j=0;j<9;j++){
            if(!pined[i][j]) continue;
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(!canJump(nx, ny, k)) continue;
                Map[i][j] = '.';
                Map[nx][ny] = '.';
                Map[nx+dx[k]][ny+dy[k]] = 'o';
                pined[nx+dx[k]][ny+dy[k]] = 1;
                pined[nx][ny] = 0;
                pined[i][j] = 0;
                go(cnt+1);
                pined[i][j] = 1;
                pined[nx][ny] = 1;
                pined[nx+dx[k]][ny+dy[k]] = 0;
                Map[nx+dx[k]][ny+dy[k]] = '.';
                Map[nx][ny] = 'o';
                Map[i][j] = 'o';
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    while(n--){
        ans = 0;
        pins = 0;
        memset(pined, 0, sizeof(pined));
        for(int i=0;i<5;i++){
            for(int j=0;j<9;j++){
                cin >> Map[i][j];
                if(Map[i][j] == 'o'){
                    pined[i][j] = 1;
                    pins++;
                }
            }
        }
        go(0);
        cout << pins - ans << " " << ans << '\n';
    }
}