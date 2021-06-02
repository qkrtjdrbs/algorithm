#include <bits/stdc++.h>
#define MAX 101
using namespace std;
int n, m, h, t[MAX][MAX][MAX], v[MAX][MAX][MAX]; 
int dx[] = { 0,0,0,0,-1,1 };
int dy[] = { 0,0,-1,1,0,0 };
int dz[] = { 1,-1,0,0,0,0 };

void go(){
    int day = 0, flag = 0;
    queue<tuple<int, int, int>> q;
    for(int k=0;k<h;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> t[k][i][j];
                if(t[k][i][j] == 1){
                    v[k][i][j] = 1;
                    q.push({k, i, j});
                } else if(t[k][i][j] == 0){
                    flag = 1;
                }
            }
        }
    }
    while(!q.empty() && flag){
        int x, y, z;
        tie(z, x, y) = q.front();
        q.pop();
        for(int i=0;i<6;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            int nz = z + dz[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h ) continue;
            if(v[nz][nx][ny] || t[nz][nx][ny] == -1) continue;
            q.push({nz, nx, ny});
            t[nz][nx][ny] = 1;
            v[nz][nx][ny] = v[z][x][y] + 1;
        }
    }
    if(!flag) cout << 0;
    else {
        for(int k=0;k<h;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(t[k][i][j] == 0){
                        flag = 0;
                    }
                    day = max(day, v[k][i][j]);
                }
            }
        }
        if(!flag) cout << -1;
        else cout << day-1;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> m >> n >> h;
    go();
}