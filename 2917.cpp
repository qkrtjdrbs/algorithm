#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, dist[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[501][501];
vector<pair<int, int>> trees;

void calculateDist(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j] = -1;
        }
    }
    queue<pair<int, int>> q;
    for(auto [x, y] : trees){
        q.push({x, y});
        dist[x][y] = 0;
    }
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(dist[nx][ny] != -1) continue;
            q.push({nx, ny});
            dist[nx][ny] = dist[x][y] + 1;
        }
    }
}

bool bfs(int limit){
    if(dist[sx][sy] < limit) return false;
    bool visited[501][501];
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny]) continue;
            if(dist[nx][ny] < limit) continue;
            q.push({nx, ny});
            visited[nx][ny] = 1;
        }
    }
    return visited[ex][ey];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == '+'){
                trees.push_back({i, j});
            } else if(Map[i][j] == 'V'){
                sx = i; sy = j;
            } else if(Map[i][j] == 'J'){
                ex = i; ey = j;
            }
        }
    }
    calculateDist();
    int l=0, r=50000, ans=-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(bfs(mid)){
            l = mid+1;
            ans = max(ans, mid);
        } else{
            r = mid-1;
        }
    }
    cout << ans;
}