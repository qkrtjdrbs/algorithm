#include <bits/stdc++.h>
using namespace std;
int n, Map[501][501], dp[501][501], ans;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int go(int x, int y){
    if(dp[x][y] == -1){
        dp[x][y] = 1;
        for(int i=0;i<4;i++){
            int fx = x+dx[i];
            int fy = y+dy[i];
            if(fx >= 0 && fx < n && fy >= 0 && fy < n){
                if(Map[x][y] < Map[fx][fy])
                    dp[x][y] = max(dp[x][y], go(fx, fy)+1);
            }
        }
    }
    return dp[x][y];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> Map[i][j];
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            ans = max(ans, go(i, j));
        }
    }   
    cout << ans;
}