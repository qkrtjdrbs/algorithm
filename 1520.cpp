#include <bits/stdc++.h>
using namespace std;
int n, m, Map[501][501], dp[501][501];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int go(int x, int y){
    if(x == n-1 && y == m-1){
        return 1;
    }
    else if(dp[x][y] == -1){
        dp[x][y] = 0;
        for(int i=0;i<4;i++){
            int fx = x+dx[i];
            int fy = y+dy[i];
            if(fx < 0 || fx >= n || fy < 0 || fy >= m || (Map[x][y] <= Map[fx][fy]))
                continue;
            dp[x][y] += go(fx, fy);
        }
    }
    return dp[x][y];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> Map[i][j];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0);
}