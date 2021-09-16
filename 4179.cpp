#include <bits/stdc++.h>
using namespace std;
int n, m, ans, jx, jy, fx, fy, Visit[1001][1001], Fire[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[1001][1001];
vector<pair<int, int>> fire;
vector<pair<int, int>> person;

void bfs(){
    queue<pair<int, int>> q;
    for(auto f : fire){
        q.push(f);
        Fire[f.first][f.second] = 1;
    }
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || Fire[nx][ny]) continue;
            if(Map[nx][ny] != '#'){
                q.push({nx, ny});
                Fire[nx][ny] = Fire[x][y] + 1;
            }
        }
    }
    for(auto p : person){
        q.push(p);
        Visit[p.first][p.second] = 1;
    }
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        if(x == 0 || y == 0 || x == n-1 || y == m-1){
            cout << Visit[x][y];
            return;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || Visit[nx][ny] || Map[nx][ny] == '#') continue;
            if(Fire[nx][ny] && Fire[nx][ny] <= Visit[x][y] + 1) continue;
            q.push({nx, ny});
            Visit[nx][ny] = Visit[x][y] + 1;
        }
    }
    cout << "IMPOSSIBLE";
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 'J'){
                person.push_back({i, j});
            } else if(Map[i][j] == 'F'){
                fire.push_back({i, j});
            }
        }
    }
    bfs();
}