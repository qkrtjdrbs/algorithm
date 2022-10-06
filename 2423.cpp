#include <bits/stdc++.h>
using namespace std;

const int INF = 987654321;

int n, m, dist[502][502][2];
int dx[] = {-1,-1,1,1};
int dy[] = {-1,1,-1,1};
char road[502][502];

bool canGo(int idx, int x, int y){
    if(idx == 0 && road[x-1][y-1] == 'b'){
        return true;
    }
    if(idx == 1 && road[x-1][y] == '/'){
        return true;
    }
    if(idx == 2 && road[x][y-1] == '/'){
        return true;
    }
    if(idx == 3 && road[x][y] == 'b'){
        return true;
    }
    return false;
}

void dijk(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++) dist[i][j][0] = dist[i][j][1] = INF;
    }
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 0});
    dist[0][0][0] = 0;
    while(!pq.empty()){
        auto [cost, x, y] = pq.top();
        pq.pop();
        cost = -cost;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n+1 || ny < 0 || ny >= m+1) continue;
            if(canGo(i, x, y)){
                if(dist[nx][ny][0] <= cost) continue;
                dist[nx][ny][0] = cost;
                pq.push({-cost, nx, ny});
            } else {
                if(dist[nx][ny][1] <= cost+1) continue;
                dist[nx][ny][1] = cost+1;
                pq.push({-(cost+1), nx, ny});
            }
        }
    }
    int ans = min(dist[n][m][0], dist[n][m][1]);
    ans == INF ? cout << "NO SOLUTION" : cout << ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> road[i][j];
            if(road[i][j] != '/') road[i][j] = 'b';
        }
    }
    dijk();
}