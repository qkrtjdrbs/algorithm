#include <bits/stdc++.h>    
using namespace std;
int n, m, ex, ey, ans, Visit[11][11][11][11];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
string Map[11];

typedef struct bead {
    int x, y;
}Bead;

Bead r, b;

void bfs(){
    queue<tuple<int, int, int, int, int>> q;
    q.push({r.x, r.y, b.x, b.y, 0});
    Visit[r.x][r.y][b.x][b.y] = 1;
    while(!q.empty()){
        int rx, ry, bx, by, cnt;
        tie(rx, ry, bx, by, cnt) = q.front();
        q.pop();
        if(cnt > 10) break;
        if(rx == ex && ry == ey){
            ans = cnt;
            break;
        }
        for(int i=0;i<4;i++){
            int nRx = rx + dx[i];
            int nRy = ry + dy[i];
            while(1){
                if(Map[nRx][nRy] == '#'){
                    nRx -= dx[i];
                    nRy -= dy[i];
                    break;
                }
                if(Map[nRx][nRy] == 'O'){
                    break;
                }
                nRx += dx[i];
                nRy += dy[i];
            }
            int nBx = bx + dx[i];
            int nBy = by + dy[i];
            bool bInHole = false;
            while(1){
                if(Map[nBx][nBy] == '#'){
                    nBx -= dx[i];
                    nBy -= dy[i];
                    break;
                }
                if(Map[nBx][nBy] == 'O'){
                    bInHole = true;
                    break;
                }
                nBx += dx[i];
                nBy += dy[i];
            }
            if(bInHole) continue;
            if(nRx == nBx && nRy == nBy){
                if(i == 0) ry > by ? nRy++ : nBy++;
                else if(i == 1) ry > by ? nBy-- : nRy--;
                else if(i == 2) rx > bx ? nRx++ : nBx++;
                else rx > bx ? nBx-- : nRx--;
            }
            if(Visit[nRx][nRy][nBx][nBy]) continue;
            Visit[nRx][nRy][nBx][nBy] = 1;
            q.push({nRx, nRy, nBx, nBy, cnt+1});
        }
    }
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        cin >> Map[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 'O'){
                ex = i;
                ey = j;
            } else if(Map[i][j] == 'R'){
                r = {i, j};
            } else if(Map[i][j] == 'B'){
                b = {i, j};
            }
        }
    }
    bfs();
    ans == 0 ? cout << ans : cout << 1;
}