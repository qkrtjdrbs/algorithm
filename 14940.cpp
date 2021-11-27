#include <bits/stdc++.h>
using namespace std;

int n, m, Map[1001][1001], visited[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    queue<pair<int, int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
            if(Map[i][j] == 2){
                q.push({i, j});
                visited[i][j] = 1;
            }
        }
    }
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny] || !Map[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]) Map[i][j] ? cout << -1 : cout << 0;
            else cout << visited[i][j] - 1;
            cout << " ";
        }
        cout << '\n';
    }
}