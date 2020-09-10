#include <iostream>
#include <algorithm>
using namespace std;
int N, color[1001][3], dp[1001][3], ans=987654321;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> color[i][0] >> color[i][1] >> color[i][2];
    }
    for (int j=0;j<3;j++) {
        for (int i=0;i<3;i++) {
            if (j==i)
                dp[1][j]=color[1][i];
            else
                dp[1][i]=987654321;
        }
        for (int i=2;i<=N;i++) {
            dp[i][0]=min(dp[i-1][1], dp[i-1][2])+color[i][0];
            dp[i][1]=min(dp[i-1][0], dp[i-1][2])+color[i][1];
            dp[i][2]=min(dp[i-1][0], dp[i-1][1])+color[i][2];
        }
        for (int i=0;i<3;i++) {
            if (i==j) continue;
            ans=min(ans, dp[N][i]);
        }
    }
    cout << ans;
}