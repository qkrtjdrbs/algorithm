#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, m, Map[301][301], dist[301][301];
int dx[] = {0,1};
int dy[] = {1,0};

void bfs(){
    queue<pair<int, int>> q;
    q.push({0,0});
    dist[0][0] = 1;
    while(!q.empty()){
        auto [x, y] = q.front();
        q.pop();
        for(int k=1;k<=Map[x][y];k++){
            for(int i=0;i<2;i++){
                int nx = x + dx[i] * k;
                int ny = y + dy[i] * k;
                int nc = dist[x][y] + 1;
                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(dist[nx][ny]) continue;
                if(nx == n-1 && ny == m-1){
                    cout << dist[x][y];
                    return;
                }
                q.push({nx, ny});
                dist[nx][ny] = nc;
            }
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
    bfs();
}