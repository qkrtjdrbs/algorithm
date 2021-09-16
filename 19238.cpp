#include <bits/stdc++.h>
using namespace std;

pair<int, int> taxi, dest[21][21];
vector<pair<int, int>> passengers;
int n, m, fuel, visited[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool Map[21][21];

void bfs(int sx, int sy){
    memset(visited, 0, sizeof(visited));
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
            if(nx <= 0 || nx > n || ny <= 0 || ny > n || Map[nx][ny]) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void go(int cnt){
    for(int i=0;i<cnt;i++){
        bfs(taxi.first, taxi.second);
        priority_queue<tuple<int, int, int>> pq;
        for(auto p : passengers){
            int sx, sy;
            tie(sx, sy) = p;
            pq.push({-visited[sx][sy], -sx, -sy});
        }
        int x, y, f;
        tie(f, x, y) = pq.top();
        f++;
        f = -f; x = -x; y = -y;
        if(f > fuel || f < 0) {
            cout << -1;
            return;
        }
        fuel -= f;
        for(int j=0;j<passengers.size();j++){
            int sx, sy;
            tie(sx, sy) = passengers[j];
            if(x == sx && y == sy) {
                passengers.erase(passengers.begin()+j);
                break;
            }
        }
        int nx, ny, nf;
        tie(nx, ny) = dest[x][y];
        bfs(x, y);
        nf = visited[nx][ny] - 1;
        if(nf > fuel || nf < 0) {
            cout << -1;
            return;
        }
        fuel += nf;
        taxi = {nx, ny};
    }
    if(!passengers.empty()){
         cout << -1;
         return;
    }
    cout << fuel;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> fuel;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)
            cin >> Map[i][j];
    }
    int sx, sy;
    cin >> sx >> sy;
    taxi = {sx, sy};
    for(int i=0;i<m;i++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        passengers.push_back({sx, sy});
        dest[sx][sy] = {ex, ey};
    }
    int cnt = passengers.size();
    bfs(sx, sy);
    go(cnt);
}