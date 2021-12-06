#include <bits/stdc++.h>
using namespace std;

int n, k, r, visited[101][101], cnt[10001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool road[101][101][4], cow[101][101];

void bfs(int sx, int sy, int com){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = com;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(visited[nx][ny] || road[x][y][i]) continue;
            q.push({nx, ny});
            visited[nx][ny] = com;
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k >> r;
    for(int i=0;i<r;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if(a > c) road[a-1][b-1][2] = road[c-1][d-1][3] = 1;
        else if(a < c) road[a-1][b-1][3] = road[c-1][d-1][2] = 1;
        else if(b > d) road[a-1][b-1][0] = road[c-1][d-1][1] = 1;
        else if(b < d) road[a-1][b-1][1] = road[c-1][d-1][0] = 1;
    }
    for(int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        cow[a-1][b-1] = 1;
    }
    int com = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j]){
                bfs(i, j, com);
                com++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(cow[i][j]) cnt[visited[i][j]]++;
        }
    }
    int ans = 0;
    for(int i=1;i<=com;i++){
        for(int j=i+1;j<=com;j++){
            ans += cnt[i] * cnt[j];
        }
    }
    cout << ans;
}