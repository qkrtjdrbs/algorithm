#include <bits/stdc++.h>
using namespace std;
int n;
long Map[101][101], dp[101][101];

long go(int x, int y){
    if(x == n-1 && y == n-1) return 1;
    if(dp[x][y] != -1) return dp[x][y];
    dp[x][y] = 0;
    int down = x + Map[x][y]; 
    int right = y + Map[x][y];
    if(down < n) dp[x][y] += go(down, y);
    if(right < n) dp[x][y] += go(x, right);
    return dp[x][y];
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> Map[i][j];
    memset(dp, -1, sizeof(dp));
    cout << go(0, 0);
}