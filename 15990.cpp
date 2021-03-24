#include <iostream>
#define X 1000000009
using namespace std;
long long t, n, dp[100001][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    dp[1][1] = 1;
    dp[2][2] = 1;
    dp[3][1] = 1;
    dp[3][2] = 1;
    dp[3][3] = 1;
    while (t--)
    {
        cin >> n;
        for (int i = 4; i <= n; i++)
        {
            dp[i][1] = (dp[i - 1][2] + dp[i - 1][3]) % X;
            dp[i][2] = (dp[i - 2][1] + dp[i - 2][3]) % X;
            dp[i][3] = (dp[i - 3][1] + dp[i - 3][2]) % X;
            
        }
        cout << (dp[n][1] + dp[n][2] + dp[n][3]) % X << '\n';
    }
}