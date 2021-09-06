#include <bits/stdc++.h>
using namespace std;

int n, m, visited[1001][1001];
int dx[] = {-1,1,0,0,-1,-1,1,1};
int dy[] = {0,0,-1,1,-1,1,-1,1};
vector<pair<int, int>> v;
string Map[1001];

void bfs(){
    queue<pair<int, int>> q;
    for(auto start : v){
        int x, y;
        tie(x, y) = start;
        q.push({x, y});
    }
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int k=0;k<8;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] != '.' && Map[nx][ny] >= '1'){
                int next = Map[nx][ny] - '0';
                next--;
                Map[nx][ny] = next <= 0 ? '0' : next + '0';
                if(Map[nx][ny] == '0') {
                    q.push({nx, ny});
                    visited[nx][ny] = visited[x][y] + 1;
                }
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans, visited[i][j]);
        }
    }
    cout << ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> Map[i];

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == '.'){
                for(int k=0;k<8;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                    if(Map[nx][ny] != '.' && Map[nx][ny] >= '1'){
                        int x = Map[nx][ny] - '0';
                        x--;
                        Map[nx][ny] = x <= 0 ? '0' : x + '0';
                        if(Map[nx][ny] == '0') {
                            v.push_back({nx, ny});
                            visited[nx][ny] = 1;
                        }
                    }
                }
            }
        }
    }
    bfs();
}