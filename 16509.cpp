#include <bits/stdc++.h>
using namespace std;

int Map[10][9], visited[10][9];
int sx, sy, ex, ey;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int ddx[4][2] = {{-1,1},{-1,1},{-1,-1},{1,1}};
int ddy[4][2] = {{-1,-1},{1,1},{-1,1},{-1,1}};

bool check(int nx, int ny){
    return nx < 0 || nx >= 10 || ny < 0 || ny >= 9;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> sx >> sy >> ex >> ey;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(check(nx, ny) || (nx == ex && ny == ey)) continue;
            for(int j=0;j<2;j++){
                bool flag = true;
                for(int k=1;k<=2;k++){
                    int nnx = nx + ddx[i][j] * k;
                    int nny = ny + ddy[i][j] * k;
                    if(check(nnx, nny) || (nnx == ex && nny == ey)){
                        flag = false;
                        continue;
                    }
                }
                int nnx = nx + ddx[i][j] * 2;
                int nny = ny + ddy[i][j] * 2;
                if(nnx == ex && nny == ey){
                    cout << visited[x][y];
                    return 0;
                }
                if(flag && !visited[nnx][nny]){
                    q.push({nnx, nny});
                    visited[nnx][nny] = visited[x][y] + 1;
                }
            }
        }
    }
    cout << -1;
}