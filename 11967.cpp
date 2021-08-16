#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[101][101], Map[101][101];
vector<pair<int, int>> rooms[101][101];

int bfs(){
    int res = 1;
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;
    Map[0][0] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        vector<pair<int, int>> v;
        if(Map[x][y] != 2){
            for(auto next : rooms[x][y]){
                int nx, ny;
                tie(nx, ny) = next;
                if(visited[nx][ny]) continue;
                if(!Map[nx][ny]){
                    Map[nx][ny] = 1;
                    v.push_back({nx, ny});
                    res++;
                }
                Map[x][y] = 2;
            }
        }
        if(!v.empty()){
            memset(visited, 0, sizeof(visited));
            visited[x][y] = 1;
            while(!q.empty()) q.pop();
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(!visited[nx][ny] && Map[nx][ny]){
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        rooms[a-1][b-1].push_back({c-1, d-1});
    }
    cout << bfs();
}