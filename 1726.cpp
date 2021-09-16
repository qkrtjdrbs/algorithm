#include <bits/stdc++.h>
using namespace std;
int Map[101][101], Visit[101][101][5], n, m;
int dx[] = {0,0,0,1,-1};
int dy[] = {0,1,-1,0,0};

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> Map[i][j];
        }
    }
    queue<tuple<int, int, int>> q;
    int a, b, d, ex, ey, ed, ans;
    cin >> a >> b >> d;
    cin >> ex >> ey >> ed;
    q.push({a, b, d});
    Visit[a][b][d] = 1;
    while(!q.empty()){
        int x, y, d;
        tie(x, y, d) = q.front();
        q.pop();
        if(x == ex && y == ey && d == ed){
            ans = Visit[ex][ey][ed];
            break;
        }
        for(int i=1;i<=3;i++){
            int nx = x + dx[d] * i;
            int ny = y + dy[d] * i;
            if(Visit[nx][ny][d]) continue;
            if(nx <= 0 || nx > n || ny <= 0 || ny > m || Map[nx][ny] == 1) break;
            Visit[nx][ny][d] = Visit[x][y][d] + 1;
            q.push({nx, ny, d});
        }
        for(int i=1;i<=4;i++){
            if(d != i && !Visit[x][y][i]){
                if((d==1 && i==2) || (d==2 && i==1) || (d==3 && i==4) || (d==4 && i==3)){
                    q.push({x, y, i});
                    Visit[x][y][i] = Visit[x][y][d] + 2;
                }
                else{
                    q.push({x, y, i});
                    Visit[x][y][i] = Visit[x][y][d] + 1;
                }
            }
        }
    }
    cout << ans - 1;
}