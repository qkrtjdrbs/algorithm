#include <bits/stdc++.h>
using namespace std;

int n, q, Map[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
bool visited[101][101];
vector<int> levels;

void rotate(int sx, int sy, int len){
    int tmp[101][101], tmp2[101][101];
    for(int i=sx;i<sx+len;i++){
        for(int j=sy;j<sy+len;j++){
            tmp2[i-sx][j-sy] = Map[i][j];
        }
    }
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            tmp[i][j] = tmp2[len-1-j][i];
        }
    }
    for(int i=sx;i<sx+len;i++){
        for(int j=sy;j<sy+len;j++){
            Map[i][j] = tmp[i-sx][j-sy];
        }
    }
}

void melt(){
    int tmp[101][101];
    memcpy(tmp, Map, sizeof(Map));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(Map[i][j]){
                int cnt = 0;
                for(int k=0;k<4;k++){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                    if(!Map[nx][ny]) continue;
                    cnt++;
                }
                if(cnt < 3) tmp[i][j]--;
            }
        }
    }
    memcpy(Map, tmp, sizeof(tmp));
}

void go(int len){
    for(int sx=0;sx<n;sx+=len){
        for(int sy=0;sy<n;sy+=len){
            rotate(sx, sy, len);
        }
    }
    melt();
}

int iceSum(){
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans += Map[i][j];
        }
    }
    return ans;
}

int dfs(int x, int y){
    int res = 0;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
        if(visited[nx][ny] || !Map[nx][ny]) continue;
        visited[nx][ny] = 1;
        res += 1 + dfs(nx, ny);
    }
    return res;
}

int biggestChunk(){
    memset(visited, 0, sizeof(visited));
    int res = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(Map[i][j] && !visited[i][j]){
                visited[i][j] = 1;
                res = max(res, 1+dfs(i, j));
            }
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> q;
    n = pow(2, n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) cin >> Map[i][j];
    }
    for(int i=0;i<q;i++){
        int lv;
        cin >> lv;
        levels.push_back(pow(2, lv));
    }
    for(auto level : levels){
        go(level);
    }
    cout << iceSum() << '\n' << biggestChunk();
}