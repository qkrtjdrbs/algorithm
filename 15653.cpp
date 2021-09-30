#include <bits/stdc++.h>
using namespace std;

int n, m, rx, ry, bx, by;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[11][11][11][11];
string Map[11];

void bfs(){
    queue<tuple<int, int, int, int, int>> q;
    q.push({rx, ry, bx, by, 0});
    visited[rx][ry][bx][by] = 1;
    while(!q.empty()){
        int crx, cry, nrx, nry, cbx, cby, nbx, nby, cnt;
        tie(crx, cry, cbx, cby, cnt) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            bool rh = false, bh = false;
            nrx = crx; nry = cry;
            nbx = cbx; nby = cby;
            while(0 <= nrx && nrx < n && 0 <= nry && nry < m && Map[nrx][nry] != '#'){
                if(Map[nrx][nry] == 'O'){
                    rh = true;
                    break;
                }
                nrx += dx[i];
                nry += dy[i];
            }
            if(nrx < 0 || nrx >= n || nry < 0 || nry >= m || Map[nrx][nry] == '#'){
                nrx -= dx[i];
                nry -= dy[i];
            }
            while(0 <= nbx && nbx < n && 0 <= nby && nby < m && Map[nbx][nby] != '#'){
                if(Map[nbx][nby] == 'O'){
                    bh = true;
                    break;
                }
                nbx += dx[i];
                nby += dy[i];
            }
            if(nbx < 0 || nbx >= n || nby < 0 || nby >= m || Map[nbx][nby] == '#'){
                nbx -= dx[i];
                nby -= dy[i];
            }
            if(bh) continue;
            if(rh) {
                cout << cnt+1;
                return;
            }
            if(nrx == nbx && nry == nby){
                if(i == 0) cry < cby ? nby -= dy[i] : nry -= dy[i];
                else if(i == 1) cry < cby ? nry -= dy[i] : nby -= dy[i];
                else if(i == 2) crx < cbx ? nbx -= dx[i] : nrx -= dx[i];
                else if(i == 3) crx < cbx ? nrx -= dx[i] : nbx -= dx[i];
            }
            if(!visited[nrx][nry][nbx][nby]){
                visited[nrx][nry][nbx][nby] = 1;
                q.push({nrx, nry, nbx, nby, cnt+1});
            }
        }
    }
    cout << -1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> Map[i];
        for(int j=0;j<m;j++){
            if(Map[i][j] == 'R'){
                rx = i; ry = j;
            } else if(Map[i][j] == 'B'){
                bx = i; by = j;
            }
        }
    }
    bfs();
}