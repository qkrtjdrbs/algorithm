#include <bits/stdc++.h>
using namespace std;

typedef struct passenger {
    int sx, sy, ex, ey;
}Pass;

pair<int, int> taxi, dest[21][21];
vector<pair<int, int>> passengers;
int n, m, fuel, visited[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool Map[21][21];

void bfs(int sx, int sy){
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= n || Map[nx][ny]) continue;
            if(!visited[nx][ny]){
                visited[nx][ny] = visited[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

void go(){
    for(int i=0;i<passengers.size();i++){
        priority_queue<tuple<int, int, int>> pq;
        for(auto p : passengers){
            int sx, sy;
            tie(sx, sy) = p;
            pq.push({-abs(visited[sx][sy]-visited[taxi.first][taxi.second]), -sx, -sy});
        }
        int x, y, f;
        tie(f, x, y) = pq.top();
        f = -f; x = -x; y = -y;
        if(f > fuel) {
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
        nf = abs(visited[nx][ny] - visited[x][y]);
        if(nf > fuel) {
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
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cin >> Map[i][j];
    }
    int sx, sy;
    cin >> sx >> sy;
    taxi = {sx-1, sy-1};
    for(int i=0;i<m;i++){
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        passengers.push_back({sx-1, sy-1});
        dest[sx-1][sy-1] = {ex-1, ey-1};
    }
    bfs(sx-1, sy-1);
    go();
}