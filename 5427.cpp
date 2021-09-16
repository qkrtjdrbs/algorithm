#include <bits/stdc++.h>
using namespace std;
int t, n, m, ans, sx, sy, fire[1001][1001], v[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
string Map[1001];

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        ans = 987654321;
        cin >> m >> n;
        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            cin >> Map[i];
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Map[i][j] == '@'){
                    sx = i;
                    sy = j;
                    v[i][j] = 1;
                } else if(Map[i][j] == '*'){
                    q.push({i, j});
                    fire[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(Map[nx][ny] == '.' || Map[nx][ny] == '@'){
                    if(!fire[nx][ny]){
                        fire[nx][ny] = fire[x][y] + 1;
                        q.push({nx, ny});
                    } else if(fire[nx][ny] > fire[x][y] + 1){
                        fire[nx][ny] = fire[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        q.push({sx, sy});
        while(!q.empty()){
            int x, y;
            tie(x, y) = q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
                    ans = min(ans, v[x][y]);
                    continue;
                }
                if(Map[nx][ny] == '.' && !v[nx][ny]){
                    if(!fire[nx][ny]){
                        v[nx][ny] = v[x][y] + 1;
                        q.push({nx, ny});
                    } else if(fire[nx][ny] > v[x][y] + 1){
                        v[nx][ny] = v[x][y] + 1;
                        q.push({nx, ny});
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            Map[i].clear();
            for(int j=0;j<m;j++){
                fire[i][j] = v[i][j] = 0;
            }
        }
        if(ans == 987654321) cout << "IMPOSSIBLE" << '\n';
        else cout << ans << '\n';
    }
}