#include <bits/stdc++.h>
#define MOD 1234567
using namespace std;

int t, n, ans, pad[4][4] = {{1,2,3},{4,5,6},{7,8,9},{0,0,0}}, dp[4][4][1001];
int dx[] = {0,0,-1,1};
int dy[] = {-1,1,0,0};

int go(int x, int y, int len){
    if(len == n){
        return 1;
    }
    int &res = dp[x][y][len];
    if(res != -1) return res;
    res = 0;
    for(int i=0;i<4;i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 4 || ny < 0 || ny >= 3) continue;
        if(nx == 3 && ny != 0) continue;
        res += (go(nx, ny, len+1) % MOD);
    }
    return res % MOD;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        cin >> n;
        ans = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                ans += (go(i, j, 1) % MOD);
            }
        }
        ans += (go(3, 0, 1) % MOD);
        cout << ans % MOD << '\n';
    }
}