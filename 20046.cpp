#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;
int n, m, Map[1001][1001], dist[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void dijk(){
    if(Map[0][0] == -1){
        cout << -1;
        return;
    }
    priority_queue<tuple<int, int, int>> pq;
    pq.push({-Map[0][0], 0, 0});
    dist[0][0] = Map[0][0];
    while(!pq.empty()){
        auto [cost, x, y] = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x][y] < cost) continue;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nc = cost;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] == -1) continue;
            else if(Map[nx][ny] == 1) nc += 1;
            else if(Map[nx][ny] == 2) nc += 2;
            if(dist[nx][ny] <= nc) continue;
            pq.push({-nc, nx, ny});
            dist[nx][ny] = nc;
        }
    }
    cout << (dist[n-1][m-1] == INF ? -1 : dist[n-1][m-1]);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            dist[i][j] = INF;
        }
    }
    dijk();
}