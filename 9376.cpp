#include <bits/stdc++.h>
#define MAX 987654321;
using namespace std;
int t, n, m, dist[102][102][3], Visit[102][102], ans=MAX;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

char Map[102][102];

void bfs(int i, int j, int k){
    priority_queue<tuple<int, int, int, int>> pq;
    dist[i][j][k] = 0;
    Visit[i][j] = 1;
    pq.push({0, i, j, k});
    while(!pq.empty()){
        int cost, x, y, z;
        tie(cost, x, y, z) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x][y][z] > cost){
            dist[x][y][z] = cost;
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] != '*'){
                if(Map[nx][ny] == '#'){
                    if(dist[nx][ny][k] > dist[x][y][k] + 1){
                        pq.push({-(dist[x][y][k] + 1), nx, ny, k});
                    }
                } else if(Map[nx][ny] == '.'){
                    if(dist[nx][ny][k] > dist[x][y][k]){
                        pq.push({-dist[x][y][k], nx, ny, k});
                    }
                }
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int x1, y1, x2, y2;
        cin >> n >> m;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            string s;
            cin >> s;
            for(int j=1;j<=m;j++){
                dist[i][j][0] = MAX;
                dist[i][j][1] = MAX;
                dist[i][j][2] = MAX;
                Map[i][j] = s[j];
                if(s[j] == '$'){
                    if(!cnt){
                        x1 = i;
                        y1 = j;
                        cnt++;
                    } else {
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }
        for(int i=0;i<=m+1;i++){
            Map[0][i] = '.';
            Map[n+1][i] = '.';
        }
        for(int i=0;i<=n+1;i++){
            Map[i][0] = '.';
            Map[i][m+1] = '.';
        }
        bfs(x1, y1, 0);
        bfs(x2, y2, 1);
        bfs(0, 0, 2);
        cout << ans << '\n';
    }
}