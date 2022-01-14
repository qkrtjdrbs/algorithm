#include <bits/stdc++.h>
using namespace std;

int n, m, t, d, visited[26][26][2];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
int Map[26][26];

void bfs(bool flag){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            visited[i][j][flag] = 987654321;
        }
    }
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 0});
    visited[0][0][flag] = 0;
    while(!pq.empty()){
        int x, y, cost;
        tie(cost, x, y) = pq.top();
        pq.pop();
        cost = -cost;
        if(visited[x][y][flag] < cost) continue;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(abs(Map[x][y]-Map[nx][ny]) > t) continue;
            if(!flag){
                if(Map[x][y] < Map[nx][ny]){
                    int nc = pow(abs(Map[x][y]-Map[nx][ny]), 2) + cost;
                    if(visited[nx][ny][flag] > nc){
                        visited[nx][ny][flag] = nc;
                        pq.push({-nc, nx, ny});
                    }
                } else {
                    int nc = cost + 1;
                    if(visited[nx][ny][flag] > nc){
                        visited[nx][ny][flag] = nc;
                        pq.push({-nc, nx, ny});
                    }
                }
            } else {
                if(Map[x][y] <= Map[nx][ny]){                 
                    int nc = cost + 1;
                    if(visited[nx][ny][flag] > nc){
                        visited[nx][ny][flag] = nc;
                        pq.push({-nc, nx, ny});
                    }
                } else {
                    int nc = pow(abs(Map[x][y]-Map[nx][ny]), 2) + cost;
                    if(visited[nx][ny][flag] > nc){
                        visited[nx][ny][flag] = nc;
                        pq.push({-nc, nx, ny});
                    }
                }
            }
        }
    } 
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> t >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char x;
            cin >> x;
            if('A' <= x && x <= 'Z') Map[i][j] = x - 'A';
            else Map[i][j] = x - 'a' + 26;
        }
    }
    bfs(0); bfs(1);
    int res = Map[0][0];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(visited[i][j][0] + visited[i][j][1] <= d){
                res = max(res, Map[i][j]);
           }
        }
    }
    cout << res;
}