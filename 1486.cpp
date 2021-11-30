#include <bits/stdc++.h>
using namespace std;

int n, m, t, d, dp[26][26][26][26];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};
char Map[26][26];

int go(int cx, int cy, int px, int py, int times){
    int &res = dp[cx][cy][px][py];
    if(res != -1) return res;
    res = Map[cx][cy] - 'A';
    for(int i=0;i<4;i++){
        int nx = cx + dx[i];
        int ny = cy + dy[i];
        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if(px == nx && py == ny) continue;
        int diff = abs(Map[cx][cy] - Map[nx][ny]);
        if(diff > t) continue;
        if(Map[cx][cy] >= Map[nx][ny]){
            if(times + 1 <= d) res = max(res, go(nx, ny, cx, cy, times+1));
        } else {
            if(times + pow(diff, 2) <= d) res = max(res, go(nx, ny, cx, cy, times+pow(diff, 2)));
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> t >> d;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> Map[i][j];
        }
    }
    memset(dp, -1, sizeof(dp));
    cout << go(0,0,0,0,0);
}