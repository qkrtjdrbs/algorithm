#include <bits/stdc++.h>
using namespace std;

int n, m, k, visited[101][101];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[101][101];

void destroy(int h, int flag){
    if(!flag){
        for(int i=0;i<m;i++){
            if(Map[h][i] == 'x'){
                Map[h][i] = '.';
                break;
            }
        }
    } else {
        for(int i=m-1;i>=0;i--){
            if(Map[h][i] == 'x'){
                Map[h][i] = '.';
                break;
            }
        }
    }
}

void bfs(int sx, int sy, int c){
    queue<pair<int, int>> q;
    q.push({sx, sy});
    visited[sx][sy] = c;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] == '.' || visited[nx][ny]) continue;
            q.push({nx, ny});
            visited[nx][ny] = c;
        }
    }
}

void gravity(){
    memset(visited, 0, sizeof(visited));
    int flag = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 'x' && !visited[i][j]){
                bfs(i, j, flag);
                flag++;
            }
        }
    }
    for(int f=1;f<flag;f++){
        int len = n;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited[i][j] != f) continue;
                int tmp = 0;
                for(int k=i+1;k<n;k++){
                    if(Map[k][j] == '.') tmp++;
                    if(Map[k][j] == 'x' && visited[k][j] != visited[i][j]) break;
                }
                len = min(len, tmp);
            }
        }
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<m;j++){
                if(visited[i][j] == f){
                    Map[i][j] = '.';
                    Map[i+len][j] = 'x';
                }
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++) cin >> Map[i][j];
    }
    cin >> k;
    for(int i=0;i<k;i++){
        int h;
        cin >> h;
        h = n - h;
        destroy(h, (i % 2));
        gravity();
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout << Map[i][j];
        }
        cout << '\n';
    }
}