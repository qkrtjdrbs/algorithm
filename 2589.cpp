#include <bits/stdc++.h>
using namespace std;
int n, m, Map[51][51], Visit[51][51];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int bfs(int x, int y){
    int res = 0;
    queue<pair<int, int>> q;
    q.push({x, y});
    Visit[x][y] = 1;
    while(!q.empty()){
        int x, y;
        tie(x, y) = q.front();
        q.pop();
        res = max(res, Visit[x][y]);
        for(int i=0;i<4;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(!Visit[nx][ny] && Map[nx][ny]){
                Visit[nx][ny] = Visit[x][y]+1;
                q.push({nx, ny});
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Visit[i][j] = 0;
        }
    }
    return res-1;
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<m;j++){
            if(s[j] == 'W'){
                Map[i][j] = 0;
            } else {
                Map[i][j] = 1;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j]){
                ans = max(ans, bfs(i, j));
            }
        }
    }
    cout << ans; 
}