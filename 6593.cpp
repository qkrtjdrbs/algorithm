#include <bits/stdc++.h>
#define MAX 31
using namespace std;
int l, r, c, startX, startY, startZ, endX, endY, endZ, v[MAX][MAX][MAX];
int dx[] = {0,0,-1,1,0,0};
int dy[] = {-1,1,0,0,0,0};
int dz[] = {0,0,0,0,1,-1};
string m[MAX][MAX];

void init(){
    for(int k=0;k<MAX;k++){
        for(int i=0;i<MAX;i++){
            m[k][i].clear();
            for(int j=0;j<MAX;j++){
                v[k][i][j] = 0;
            }
        }
    }
}

int bfs(int sx, int sy, int sz){
    queue<tuple<int, int, int>> q;
    q.push({sz, sx, sy});
    v[sz][sx][sy] = 1;
    while(!q.empty()){
        int x, y, z;
        tie(z, x, y) = q.front();
        q.pop();
        if(m[z][x][y] == 'E') break;
        for(int k=0;k<6;k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nz = z + dz[k];
            if(nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) continue;
            if(m[nz][nx][ny] == '#') continue;
            if(!v[nz][nx][ny]) {
                v[nz][nx][ny] = v[z][x][y] + 1;
                q.push({nz, nx, ny});
                continue;
            }
            if(v[nz][nx][ny] > v[z][x][y] + 1){
                v[nz][nx][ny] = v[z][x][y] + 1;
                q.push({nz, nx, ny});
            }
        }
    }
    return v[endZ][endX][endY];
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(1){
        init();
        cin >> l >> r >> c;
        if(!l && !r && !c) break;
        for(int k=0;k<l;k++){
            for(int i=0;i<r;i++){
                cin >> m[k][i];
                for(int j=0;j<c;j++){
                    if(m[k][i][j] == 'S'){
                        startZ = k;
                        startX = i;
                        startY = j;
                    } else if(m[k][i][j] == 'E'){
                        endZ = k;
                        endX = i;
                        endY = j;
                    }
                }
            }
        }
        int ans = bfs(startX, startY, startZ);
        if(!ans) cout << "Trapped!";
        else cout << "Escaped in " << ans-1 << " minute(s).";
        cout << '\n';
    }
}