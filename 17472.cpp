#include <bits/stdc++.h>
#define BRIDGE 7
using namespace std;
int n, m, otherLand, Map[11][11], Visit[11][11], parent[8];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
priority_queue<tuple<int, int, int>> pq;

void coloring(int x, int y, int c){
    Visit[x][y] = 1;
    Map[x][y] = c;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(!Visit[nx][ny] && Map[nx][ny] == 1){
            coloring(nx, ny, c);
        }
    }
}

int bridge(int startLand, int x, int y, int dir){
    if(x < 0 || x >= n || y < 0 || y >= m || Map[x][y] == startLand) return -99;
    if(Map[x][y] != startLand && Map[x][y] >= 2){
        otherLand = Map[x][y];
        return 0;
    }
    int nx = x + dx[dir];
    int ny = y + dy[dir];
    return 1 + bridge(startLand, nx, ny, dir);
}

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int u = Find(x);
    int v = Find(y);
    parent[u] = v;
}


int main(){
    cin >> n >> m;
    for(int i=0;i<8;i++){
        parent[i] = i;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin >> Map[i][j];
    }
    int color = 2;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 1 && !Visit[i][j]){
                coloring(i, j, color);
                ++color;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] >= 2){
                for(int k=0;k<4;k++){
                    int len = bridge(Map[i][j], i+dx[k], j+dy[k], k);
                    if(len <= 1) continue;
                    pq.push({-len, Map[i][j], otherLand});
                }
            }
        }
    }
    int M = 0, ans = 0;
    while(!pq.empty()){
        int cost, start, end;
        tie(cost, start, end) = pq.top();
        pq.pop();
        if(Find(start) == Find(end)) continue;
        Union(start, end);
        ans += -cost;
        ++M;
    }
    if(M != color - 3) ans = -1;
    cout << ans;
}