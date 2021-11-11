#include <bits/stdc++.h>
using namespace std;

int n, m, Map[1001][1001], visited[1001][1001], h, w, sx, sy, ex, ey;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
vector<pair<int, int>> walls;

bool cantGo(int x, int y){
    if(x < 0 || x >= n || y < 0 || y >= m) return true;
    if(x+h-1 < 0 || x+h-1 >= n || y < 0 || y >= m) return true;
    if(x+h-1 < 0 || x+h-1 >= n || y+w-1 < 0 || y+w-1 >= m) return true;
    if(x < 0 || x >= n || y+w-1 < 0 || y+w-1 >= m) return true;
    for(auto wall : walls){
        int i, j;
        tie(i, j) = wall;
        if(x <= i && i < x+h && y <= j && j < y+w) return true;
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j]) walls.push_back({i, j});
        }
    }
    cin >> h >> w >> sx >> sy >> ex >> ey;
    queue<pair<int, int>> q;
    q.push({sx-1, sy-1});
    visited[sx-1][sy-1] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if(x == ex-1 && y == ey-1){
            cout << visited[x][y]-1;
            return 0;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(cantGo(nx, ny) || visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }   
    cout << -1;
}