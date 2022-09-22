#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n, t, Map[101][101], dist[101][101][3];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

ll dijk(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            for(int k=0;k<3;k++) dist[i][j][k] = LLONG_MAX;
        }
    }
    priority_queue<tuple<ll, int, int, int>> pq;
    dist[0][0][0] = 0;
    pq.push({0, 0, 0, 0});
    while(!pq.empty()){
        auto [cost, x, y, z] = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x][y][z] > cost) continue;

        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = (z+1) % 3;
            ll nc = cost + t;
            if(nz == 0) nc += Map[nx][ny];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(dist[nx][ny][nz] <= nc) continue;
            dist[nx][ny][nz] = nc;
            pq.push({-nc, nx, ny, nz});
        }
    }
    return min({dist[n-1][n-1][0], dist[n-1][n-1][1], dist[n-1][n-1][2]});
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> Map[i][j];
    }
    cout << dijk();
}