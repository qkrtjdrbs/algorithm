#include <bits/stdc++.h>
using namespace std;

int n, m, sx=-1, sy=-1, ex=-1, ey=-1, visited[1501][1501], check[1501][1501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[1501][1501];

bool bfs(int limit){
    memset(check, 0, sizeof(check));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    check[sx][sy] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if(x == ex && y == ey) return true;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || check[nx][ny]) continue;
            if(visited[nx][ny] <= limit){
                q.push({nx, ny});
                check[nx][ny] = 1;
            }
        }
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'L'){
                if(sx == -1){
                    sx = i; sy = j;
                } else {
                    ex = i; ey = j;
                }
            }
        }
    }
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == '.' || Map[i][j] == 'L'){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
                    if(Map[nx][ny] == 'X'){
                        q.push({nx, ny});
                        visited[nx][ny] = 1;
                    }
                }
            }
        }
    }
    int l = 0, r = 0;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        r = max(r, visited[x][y]);
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) continue;
            if(Map[nx][ny] == 'X'){
                q.push({nx, ny});
                visited[nx][ny] = visited[x][y] + 1;
            }
        }
    }
    int ans = r;
    while(l <= r){
        int mid = (l+r) / 2;
        if(bfs(mid)){
            ans = min(ans, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}