#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey, dist[51][51][2];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[51][51];

bool check(int x, int y){
    return x < 0 || x >= n || y < 0 || y >= m;
}

bool isNextTo(int x, int y){
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(check(nx, ny)) continue;
        if(Map[nx][ny] == 'g'){ 
            return true;
        } 
    }
    return false;
}

void dijk(){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            dist[i][j][0] = dist[i][j][1] = 987654321;
        }
    }
    priority_queue<tuple<int, int, int, int>> pq;
    pq.push({0, 0, sx, sy});
    dist[sx][sy][0] = dist[sx][sy][1] = 0;
    while(!pq.empty()){
        auto [t, at, x, y] = pq.top();
        pq.pop();
        t = -t; at = -at;
        if(dist[x][y][0] < t) continue;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nt = t;
            int nat = at;
            if(check(nx, ny)) continue;
            if(Map[nx][ny] == 'g'){ 
                nt++;
            }
            if(isNextTo(nx, ny)){
                if(Map[nx][ny] != 'g' && (nx != ex || ny != ey)) nat++;
            }
            if(nt < dist[nx][ny][0]){
                dist[nx][ny][0] = nt;
                dist[nx][ny][1] = nat;
                pq.push({-nt, -nat, nx, ny});
            } else if(nt == dist[nx][ny][0]){
                if(nat < dist[nx][ny][1]){
                    dist[nx][ny][1] = nat;
                    pq.push({-nt, -nat, nx, ny});
                }
            }
        }
    }
    cout << dist[ex][ey][0] << " " << dist[ex][ey][1];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'S'){
                sx = i; sy = j;
            } else if(Map[i][j] == 'g'){
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(check(nx, ny)) continue;
                }
            } else if(Map[i][j] == 'F'){
                ex = i; ey = j;
            }
        }
    }
    dijk();
}