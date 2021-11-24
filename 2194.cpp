#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, k, visited[501][501];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool Map[501][501];

bool check(int x, int y){
    if(x <= 0 || x > n || y <= 0 || y > m) return false;
    if(x+a-1 <= 0 || x+a-1 > n || y+b-1 <= 0 || y+b-1 > m) return false;
    if(visited[x][y]) return false;
    for(int i=x;i<x+a;i++){
        for(int j=y;j<y+b;j++){
            if(Map[i][j]) return false;
        }
    }
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> a >> b >> k;
    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        Map[x][y] = 1;
    }
    int sx, sy, ex, ey;
    cin >> sx >> sy >> ex >> ey;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!check(nx, ny)) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    cout << visited[ex][ey]-1;
}