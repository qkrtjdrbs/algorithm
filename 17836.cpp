#include <bits/stdc++.h>
using namespace std;

int n, m, t, Map[101][101], visited[2][101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void bfs(){
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited[0][0][0] = 1;
    while(!q.empty()){
        int x, y, gram;
        tie(x, y, gram) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[gram][nx][ny]) continue;
            if(Map[nx][ny] == 1){
                if(gram){
                    q.push({nx, ny, gram});
                    visited[gram][nx][ny] = visited[gram][x][y] + 1;
                }
            } else if(Map[nx][ny] == 2){
                q.push({nx, ny, 1});
                visited[1][nx][ny] = visited[0][x][y] + 1;
            } else {
                q.push({nx, ny, gram});
                visited[gram][nx][ny] = visited[gram][x][y] + 1;
            }
        }
    }
    int ans = 987654321;
    for(int i=0;i<2;i++){
        if(!visited[i][n-1][m-1]) continue;
        ans = min(ans, visited[i][n-1][m-1]);
    }
    if(ans == 987654321 || ans - 1 > t) cout << "Fail";
    else cout << ans-1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> t;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    bfs();
}