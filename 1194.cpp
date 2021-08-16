#include <bits/stdc++.h>
using namespace std;
int n, m, sx, sy, Visit[51][51][1 << 7];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
string Map[51];
string conv = "abcdef";

void bfs(){
    queue<tuple<int, int, int>> q;
    q.push({sx, sy, 0});
    Visit[sx][sy][0] = 1;
    while(!q.empty()){
        int x, y, b;
        tie(x, y, b) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || Map[nx][ny] == '#') continue;
            if(isalpha(Map[nx][ny])){
                if(isupper(Map[nx][ny])){
                    char lAlpha = tolower(Map[nx][ny]);
                    int idx = find(conv.begin(), conv.end(), lAlpha) - conv.begin();
                    if((b & (1 << idx)) && !Visit[nx][ny][b]){
                        Visit[nx][ny][b] = Visit[x][y][b] + 1;
                        q.push({nx, ny, b});
                    }  
                } else {
                    int idx = find(conv.begin(), conv.end(), Map[nx][ny]) - conv.begin();
                    int nb = b | (1 << idx);
                    if(!Visit[nx][ny][nb]){
                        Visit[nx][ny][nb] = Visit[x][y][b] + 1;
                        q.push({nx, ny, nb});
                    }
                }
            } else {
                if(!Visit[nx][ny][b]){
                    Visit[nx][ny][b] = Visit[x][y][b] + 1;
                    q.push({nx, ny, b});
                } 
            }
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
            if(Map[i][j] == '0'){
                sx = i;
                sy = j;
                break;
            }
        }
    }
    bfs();
    int ans = 987654321;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == '1'){
                for(int k=0;k<(1 << 7);k++){
                    if(Visit[i][j][k]){
                        ans = min(ans, Visit[i][j][k]);
                    }
                }
            }
        }
    }
    ans == 987654321 ? cout << -1 : cout << ans - 1;
}