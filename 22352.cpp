#include <bits/stdc++.h>
using namespace std;

int n, m, Map[31][31][2];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[31][31];

bool bfs(int sx, int sy, int color){
    int tmp[31][31];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) tmp[i][j] = Map[i][j][0];
    }
    queue<pair<int, int>> q;
    q.push({sx, sy});
    tmp[sx][sy] = color;
    visited[sx][sy] = 1;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny][0] != Map[sx][sy][0] || visited[nx][ny]) continue;
            q.push({nx, ny});
            tmp[nx][ny] = color;
            visited[nx][ny] = 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(tmp[i][j] != Map[i][j][1]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j][0];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j][1];
    }
    bool flag = true;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j][0] != Map[i][j][1]){
                flag = false;
                break;
            }
        }
        if(!flag) break;
    }
    if(flag){
        cout << "YES";
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j][0] != Map[i][j][1] && !visited[i][j]){
                if(bfs(i, j, Map[i][j][1])){
                    cout << "YES";
                    return 0;
                }
            }
        }
    }
    cout << "NO";
}