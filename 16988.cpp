#include <bits/stdc++.h>
using namespace std;

int n, m, ans, Map[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool selected[401], visited[21][21];

int bfs(int sx, int sy){
    int res = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        res++;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || Map[nx][ny] == 1) continue;
            if(!Map[nx][ny]){
                res = -987654321;
                continue;
            }
            visited[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return res;
}

void go(int start, int cnt){
    if(cnt == 2){
        int tmp = 0;
        memset(visited, 0, sizeof(visited));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(Map[i][j] == 2 && !visited[i][j]){
                    int res = bfs(i, j);
                    if(res > 0) tmp += res;
                }
            }
        }
        ans = max(ans, tmp);
        return;
    }
    for(int i=start;i<n*m;i++){
        int x = i / m, y = i % m;
        if(!Map[x][y] && !selected[i]){
            selected[i] = 1; Map[x][y] = 1;    
            go(i+1, cnt+1);
            selected[i] = 0; Map[x][y] = 0;  
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    go(0, 0);
    cout << ans;
}