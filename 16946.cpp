#include <bits/stdc++.h>
using namespace std;

int n, m, area[1000001], Map[1001][1001], visited[1001][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int bfs(int sx, int sy, int color){
    int res = 0;
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = color;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        res++;
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || Map[nx][ny]) continue;
            visited[nx][ny] = color;
            q.push({nx, ny});
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string tmp;
        cin >> tmp;
        for(int j=0;j<m;j++){
            Map[i][j] = tmp[j] - '0';
        }
    }
    int color = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && !Map[i][j]){
                area[color] = bfs(i, j, color);
                color++;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j]){
                set<int> tmp;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= m || Map[nx][ny]) continue;
                    tmp.insert(visited[nx][ny]);
                }
                int res = 1;
                for(auto t : tmp){
                    res += area[t];
                }
                Map[i][j] = res % 10;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Map[i][j];
        }
        cout << '\n';
    }
}