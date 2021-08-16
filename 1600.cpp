#include <bits/stdc++.h>
using namespace std;
int k, n, m, Map[201][201], Visit[201][201][31];
int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
int hdx[] = {-2, -2,2,2,-1,-1,1,1};
int hdy[] = {-1, 1,-1,1,-2,2,-2,2};

void bfs(){
    queue<tuple<int, int, int>> q;
    Visit[0][0][0] = 0;
    q.push({0, 0, 0});
    while(!q.empty()){
        int x, y, cnt;
        tie(x, y, cnt) = q.front();
        q.pop();
        if(cnt < k){
            for(int i=0;i<8;i++){
                int nx = x + hdx[i];
                int ny = y + hdy[i];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || Map[nx][ny]) continue;
                if(Visit[nx][ny][cnt+1] > Visit[x][y][cnt] + 1 || Visit[nx][ny][cnt+1] == -1){
                    Visit[nx][ny][cnt+1] = Visit[x][y][cnt] + 1;
                    q.push({nx, ny, cnt+1});
                }
            }
        }
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || Map[nx][ny]) continue;
            if(Visit[nx][ny][cnt] > Visit[x][y][cnt] + 1 || Visit[nx][ny][cnt] == -1){
                Visit[nx][ny][cnt] = Visit[x][y][cnt] + 1;
                q.push({nx, ny, cnt});
            }
        }
    }
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    memset(Visit, -1, sizeof(Visit));
    cin >> k >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> Map[i][j];
    }
    bfs();
    int ans = 987654321;
    for(int i=0;i<=k;i++){
        if(Visit[n-1][m-1][i] == -1) continue;
        ans = min(Visit[n-1][m-1][i], ans);
    }       
    ans == 987654321 ? cout << -1 : cout << ans;
}