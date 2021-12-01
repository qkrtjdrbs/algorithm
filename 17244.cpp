#include <bits/stdc++.h>
using namespace std;

int n, m, sx, sy, ex, ey;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[51][51];
vector<pair<int, int>> things;
vector<int> orders;

int bfs(int sx, int sy, int ex, int ey){
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
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || Map[nx][ny] == '#') continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    return visited[ex][ey]-1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'X') things.push_back({i, j});
            else if(Map[i][j] == 'S') {
                sx = i; sy = j;
            } else if(Map[i][j] == 'E'){
                ex = i; ey = j;
            }
        }
    }
    for(int i=0;i<things.size();i++) orders.push_back(i);
    int ans = 987654321, len = orders.size();
    if(!len){
        cout << bfs(sx, sy, ex, ey);
        return 0;
    }
    do{   
        int res = bfs(sx, sy, things[orders[0]].first, things[orders[0]].second);
        for(int i=0;i<len-1;i++){
            res += bfs(things[orders[i]].first, things[orders[i]].second,
                things[orders[i+1]].first, things[orders[i+1]].second
            );
        }
        res += bfs(things[orders[len-1]].first, things[orders[len-1]].second, ex, ey);
        ans = min(ans, res);
    }while(next_permutation(orders.begin(), orders.end()));
    cout << ans;
}