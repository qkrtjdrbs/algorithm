#include <bits/stdc++.h>
using namespace std;

int n, m, ans[3], Map[51][51], Visit[51][51], room[251];
int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

int bfs(int sx, int sy, int color){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    int sum = 0;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        sum++;
        for(int i=0;i<4;i++){
            if(Map[x][y] & (1 << i)) continue;
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || Visit[nx][ny]) continue;
            q.push({nx, ny});
            Visit[nx][ny] = color;
        }
    }
    room[color] = sum;
    return sum;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> m >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> Map[i][j];
    }
    int color = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!Visit[i][j]){
                ans[0]++;
                Visit[i][j] = color;
                ans[1] = max(ans[1], bfs(i, j, color));
                color++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=0;k<4;k++){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(nx < 0 || nx >= n || ny < 0 || ny >= m || Visit[i][j] == Visit[nx][ny]) continue;
                ans[2] = max(ans[2], room[Visit[i][j]]+room[Visit[nx][ny]]);
            }
        }
    }
    for(int i=0;i<3;i++){
        cout << ans[i] << '\n';
    }
}