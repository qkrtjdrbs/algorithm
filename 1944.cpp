#include <bits/stdc++.h>
using namespace std;

int n, m, key[51][51], parent[255];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[51][51];
vector<pair<int, int>> spots;
priority_queue<tuple<int, int, int>> pq;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(x > y) parent[x] = y;
    if(x < y) parent[y] = x;
    return true;
}

void bfs(int sx, int sy){
    int visited[51][51];
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(Map[nx][ny] == '1' || visited[nx][ny]) continue;
            visited[nx][ny] = visited[x][y] + 1;
            q.push({nx, ny});
            if(Map[nx][ny] == 'K') {
                pq.push({-visited[nx][ny]+1, key[sx][sy], key[nx][ny]});
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<=m;i++) parent[i] = i;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
            if(Map[i][j] != '0' && Map[i][j] != '1'){
                key[i][j] = spots.size();
                spots.push_back({i, j});
            }
        }
    }
    for(int i=0;i<spots.size();i++){
        bfs(spots[i].first, spots[i].second);
    }
    int ans = 0;
    while(!pq.empty()){
        int cost, x, y;
        tie(cost, x, y) = pq.top();
        pq.pop();
        if(Union(x, y)){
            ans -= cost;
        }
    }
    int root = 0;
    for(int i=1;i<=m;i++){
        if(parent[i] != root){
            cout << -1;
            return 0;
        }
    }
    cout << ans;
}