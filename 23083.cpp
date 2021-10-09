#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

ll n, m, k, dp[1001][1001];
int edx[] = {0,1,1};
int edy[] = {1,1,0};
int odx[] = {-1,0,1};
int ody[] = {1,1,0};
bool hole[1001][1001];

ll go(int x, int y){
    if(x == n && y == m) return 1;
    ll &res = dp[x][y];
    if(res != -1) return res;
    res = 0;
    for(int i=0;i<3;i++){
        int nx, ny;
        if(y % 2){
            nx = x + odx[i];
            ny = y + ody[i];
        } else {
            nx = x + edx[i];
            ny = y + edy[i];
        }
        if(nx <= 0 || nx > n || ny <= 0 || ny > m || hole[nx][ny]) continue;
        res += (go(nx, ny) % MOD);
    }
    return res % MOD;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> k;
    for(int i=0;i<k;i++){
        int x, y;
        cin >> x >> y;
        hole[x][y] = 1;
    }
    cout << go(0, 0);
}