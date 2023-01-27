#include <bits/stdc++.h>
using namespace std;

int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[101][101];
int n, m, visited[101][101];
vector<int> ans;

int dfs(int x, int y, int flag){
    int res = Map[x][y] - '0';
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(visited[nx][ny] || Map[nx][ny] == 'X') continue;
        visited[nx][ny] = flag;
        res += dfs(nx, ny, flag);
    }
    return res;
}

vector<int> solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            Map[i][j] = maps[i][j];
        }
    }
    int cnt = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j] && Map[i][j] != 'X'){
                visited[i][j] = cnt;
                ans.push_back(dfs(i, j, cnt));
                cnt++;
            }
        }
    }
    sort(ans.begin(), ans.end());
    if(!ans.size()) ans.push_back(-1);
    return ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    solution({"X591X", "X1X5X", "X231X", "1XXX1"});
}