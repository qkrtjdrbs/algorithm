#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int n, m, Map[11][11];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

bool notCross(int x, int y){
    int nx[4], ny[4], flag[4] = {0,};
    for(int i=0;i<4;i++){
        nx[i] = x + dx[i];
        ny[i] = y + dy[i];
        if(nx[i] < 0 || nx[i] >= n || ny[i] < 0 || ny[i] >= n){
            flag[i] = -1;
        }
    }
    if(!flag[0] && !flag[2]){
        if(!Map[nx[0]][ny[0]] && !Map[nx[2]][ny[2]]) return false;
    }
    if(!flag[0] && !flag[3]){
        if(!Map[nx[0]][ny[0]] && !Map[nx[3]][ny[3]]) return false;
    }
    if(!flag[1] && !flag[2]){
        if(!Map[nx[1]][ny[1]] && !Map[nx[2]][ny[2]]) return false;
    }
    if(!flag[1] && !flag[3]){
        if(!Map[nx[1]][ny[1]] && !Map[nx[3]][ny[3]]) return false;
    }
    return true;
}

int bfs(){
    bool visited[11][11];
    memset(visited, 0, sizeof(visited));
    queue<tuple<int, int, int, bool>> q;
    q.push({0, 0, 0, 0});
    visited[0][0] = 1;
    while(!q.empty()){
        int x, y, t, prev;
        tie(x, y, t, prev) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t + 1;
            if(nx == n-1 && ny == n-1){
                return nt;
            }
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!Map[nx][ny] || visited[nx][ny]) continue;
            if(Map[nx][ny] == 1){
                q.push({nx, ny, nt, 0});
                visited[nx][ny] = 1;
            } else if(Map[nx][ny] >= 2){
                if(nt % Map[nx][ny] == 0 && !prev){
                    q.push({nx, ny, nt, 1});
                    visited[nx][ny] = 1;
                } else if(nt % Map[nx][ny]) q.push({x, y, nt, 0});
            }
        }
    }
    return MAX;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> Map[i][j];
    }
    int ans = MAX;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!Map[i][j] && notCross(i, j)){
                Map[i][j] = m;
                ans = min(ans, bfs());
                Map[i][j] = 0;
            }
        }
    }
    cout << ans;
}