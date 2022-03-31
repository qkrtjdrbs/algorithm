#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans=987654321;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[31][31];
bool visited[31][31];
vector<pair<int, int>> start;

void go(int x, int y, int d, int cnt, int turn){
    if(cnt == k){
        ans = min(ans, turn);
        return;
    }
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx < 0 || nx >= n || ny < 0 || ny >= m || Map[nx][ny] == '*' || visited[nx][ny]){
        for(int i=0;i<4;i++){
            if(i == d) continue;
            nx = x + dx[i];
            ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] == '*' || visited[nx][ny]) continue;
            visited[nx][ny] = 1;
            go(nx, ny, i, cnt+1, turn+1);
            visited[nx][ny] = 0;
        }
    } else {
        visited[nx][ny] = 1;
        go(nx, ny, d, cnt+1, turn);
        visited[nx][ny] = 0;
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int t=1;
    while(cin >> n >> m){
        start.clear();
        ans=987654321;
        k=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> Map[i][j];
                if(Map[i][j] == '.'){
                    start.push_back({i, j});
                    k++;
                }
            }
        }
        if(k == 1){
            ans = 0;
        } else {
            for(auto [x, y] : start){
                for(int i=0;i<4;i++){
                    memset(visited, 0, sizeof(visited));
                    visited[x][y] = 1;
                    go(x, y, i, 1, 1);
                }
            }
        }
        cout << "Case " << t << ": " << (ans == 987654321 ? -1 : ans) << '\n';
        t++;
    }
}