#include <bits/stdc++.h>
using namespace std;

int n, m, k, dp[101][101][81];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
string Map[101], word;

int dfs(int x, int y, int cnt){
    if(cnt == word.size()) return 1;
    int &res = dp[x][y][cnt];
    if(res != -1) return res;
    res = 0;
    for(int c=1;c<=k;c++){
        for(int i=0;i<4;i++){
            int nx = x + dx[i] * c;
            int ny = y + dy[i] * c;
            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(Map[nx][ny] == word[cnt]) {
                res += dfs(nx, ny, cnt+1);
            }
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++) cin >> Map[i];
    cin >> word;

    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == word[0]){
                ans += dfs(i, j, 1);
            }
        }
    }
    cout << ans;
}