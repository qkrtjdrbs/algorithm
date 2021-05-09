#include <bits/stdc++.h>
using namespace std;
int n, m, Map[1001][1001], Visit[1001][1001], ans;
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
map<int, int> M;

void dfs(int x, int y, int cnt){
    ++ans;
    Map[x][y] = cnt;
    Visit[x][y] = 1;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(Map[nx][ny] && !Visit[nx][ny])
            dfs(nx, ny, cnt);
    }
}

int go(int x, int y){
    set<int> s;
    for(int k=0;k<4;k++){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(Map[nx][ny] != 0)
            s.insert(Map[nx][ny]);
    }
    int res = 1;
    for(auto x : s){
        res += M[x];
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    int cnt = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 1 && !Visit[i][j]){
                dfs(i, j, cnt);
                M.insert({cnt++, ans});
                ans = 0;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Visit[i][j] = 0;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 0){
                ans = max(ans, go(i, j));
            }
        }
    }
    cout << ans;
}