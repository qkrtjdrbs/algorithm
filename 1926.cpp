#include <bits/stdc++.h>
using namespace std;

int n, m;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool Map[501][501], visited[501][501];

int go(int x, int y){
    int res = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited[nx][ny] || !Map[nx][ny]) continue;
        visited[nx][ny] = 1;
        res += 1 + go(nx, ny);
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    int cnt=0, mx=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && Map[i][j]){
                visited[i][j] = 1;
                cnt++;
                mx = max(mx, 1 + go(i, j));
            }
        }
    }
    cout << cnt << '\n' << mx;
}