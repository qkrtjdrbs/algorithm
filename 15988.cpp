#include <iostream>
#define div 1000000009
using namespace std;
int T, n;
long long dp[1000001];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> T;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    while (T--)
    {
        cin >> n;
        for (int i = 4; i <= n; i++)
        {
            dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % div;
        }
        cout << (dp[n]) % div << '\n';
    }
}