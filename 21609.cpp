#include <bits/stdc++.h>
using namespace std;
int n, m, area, Map[22][22], Visit[21][21], minX=99, minY=99, flag, rainbow, ans;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
priority_queue<tuple<int, int, int, int>> block;
queue<pair<int, int>> zero;

void dfs(int x, int y, int l){
    ++area;
    Visit[x][y] = 1;
    if(Map[x][y] > 0){
        flag = 1;
        if(x < minX){
            minX = x;
            minY = y;
        } else if(x == minX && y < minY){
            minY = y;
        }
    }
    if(Map[x][y] == 0){
        zero.push({x, y});
        rainbow++;
    } 
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(!Visit[nx][ny] && Map[x][y] == 0 && Map[nx][ny] == l){
                dfs(nx, ny, l);
            }
            if(!Visit[nx][ny] && (Map[nx][ny] == 0 || Map[nx][ny] == Map[x][y])){
                dfs(nx, ny, l);
            }
        }
    }
}

void eraseBlock(int x, int y, int l){
    Visit[x][y] = 1;
    Map[x][y] = -2;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(!Visit[nx][ny] && Map[x][y] == 0 && Map[nx][ny] == l){
                eraseBlock(nx, ny, l);
            }
            if(!Visit[nx][ny] && (Map[nx][ny] == 0 || Map[nx][ny] == l)){
                eraseBlock(nx, ny, l);
            }
        }
    }
}

void gravity(int x, int y){
    if(x == n-1) return;
    if(Map[x+1][y] == -1 || Map[x+1][y] >= 0){
        return;
    }
    if(Map[x+1][y] == -2){
        int tmp = Map[x+1][y];
        Map[x+1][y] = Map[x][y];
        Map[x][y] = tmp;
    }
    gravity(x+1, y);
}

void rotate(){
    int tmp[21][21];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j] = Map[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){          
            Map[n-(j+1)][i] = tmp[i][j];
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
        }
    }
    while(1){
        flag = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(Map[i][j] > 0 && !Visit[i][j]){
                    area = 0;
                    rainbow = 0;
                    minX = 99;
                    minY = 99;
                    dfs(i, j, Map[i][j]);
                    block.push({area, rainbow, minX, minY});
                    while(!zero.empty()){
                        int x, y;
                        tie(x, y) = zero.front();
                        zero.pop();
                        Visit[x][y] = 0;
                    }
                }
            }
        }
        if(!flag) break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                Visit[i][j] = 0;
            }
        }
        priority_queue<tuple<int, int, int, int>> pq;
        int x, y, z, r;
        tie(z, r, x, y) = block.top();
        if(z < 2) break;
        block.swap(pq);
        eraseBlock(x, y, Map[x][y]);
        ans += z*z;
        for(int j=0;j<n;j++){
            for(int i=n-1;i>=0;i--){
                Visit[i][j] = 0;
                if(Map[i][j] >= 0){
                    gravity(i, j);
                }
            }
        }
        rotate();
        for(int j=0;j<n;j++){
            for(int i=n-1;i>=0;i--){
                Visit[i][j] = 0;
                if(Map[i][j] >= 0){
                    gravity(i, j);
                }
            }
        }
    }
    cout << ans;
}