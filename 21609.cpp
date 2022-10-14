#include <bits/stdc++.h>
using namespace std;

int n, m, ans, Map[21][21], visited[21][21], visited2[21][21];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

void initRainbow(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!Map[i][j]){
                visited[i][j] = 0;
            }
        }
    }
}

int getBiggestGroup(){
    memset(visited, 0, sizeof(visited));
    priority_queue<tuple<int, int, int, int, int>> pq;
    int num=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(!visited[i][j] && Map[i][j] >= 1){
                int rbw=0, area=0; 
                queue<pair<int, int>> q;
                q.push({i, j});
                visited[i][j] = num;
                while(!q.empty()){
                    auto [x, y] = q.front();
                    q.pop();
                    area++;
                    if(!Map[x][y]) rbw++;
                    for(int k=0;k<4;k++){
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited[nx][ny]) continue;
                        if(Map[i][j] == Map[nx][ny] || !Map[nx][ny]){
                            q.push({nx, ny});
                            visited[nx][ny] = num;
                        }
                    }
                }
                if(area >= 2){
                    pq.push({area, rbw, i, j, num});
                }
                initRainbow();
                num++;
            }
        }
    }
    if(pq.empty()) return -1;
    auto [a, b, c, d, e] = pq.top();
    return e;
}

int dfs(int x, int y, int num){
    int res = 0;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n || visited2[nx][ny]) continue;
        if(visited[nx][ny] == num || !Map[nx][ny]){
            visited2[nx][ny] = 1;
            Map[nx][ny] = -2;
            res += 1 + dfs(nx, ny, num);
        }
    }
    return res;
}

int eraseBlock(int num){
    int res = 0;
    memset(visited2, 0, sizeof(visited2));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(visited[i][j] == num && !visited2[i][j]){
                Map[i][j] = -2;
                visited2[i][j] = 1;
                res = 1 + dfs(i, j, num);
                return res;
            }
        }
    }
    return res;
}

void gravity(){
    for(int j=0;j<n;j++){
        for(int i=n-1;i>=0;i--){
            if(Map[i][j] > -1){
                for(int k=i;k<n-1;k++){
                    if(Map[k+1][j] == -2){
                        swap(Map[k][j], Map[k+1][j]);
                    } else break;
                }
            }
        }
    }
}

void rotate(){
    int tmp[21][21];
    for(int i=0;i<21;i++){
        for(int j=0;j<21;j++){
            tmp[i][j] = -2;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            tmp[i][j] = Map[j][n-i-1];
        }
    }
    memcpy(Map, tmp, sizeof(tmp));
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> Map[i][j];
        }
    }
    while(1){
        int num = getBiggestGroup();
        if(num == -1) break;
        ans += pow(eraseBlock(num), 2);
        gravity();
        rotate();
        gravity();
    }
    cout << ans;
}