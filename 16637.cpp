#include <iostream>
#include <algorithm>
#include <string>
#include <limits>
using namespace std;
int n, ans = INT32_MIN;
string s;

int cal(int a, int b, char op)
{
    int result = a;
    switch (op)
    {
    case '+':
        result += b;
        break;
    case '-':
        result -= b;
        break;
    case '*':
        result *= b;
        break;
    }
    return result;
}

void dfs(int idx, int cur)
{
    if (idx > n - 1)
    {
        ans = max(ans, cur);
        return;
    }
    char op = (idx == 0) ? '+' : s[idx - 1];
    if (idx < n - 2)
    {
        int bra = cal(s[idx] - '0', s[idx + 2] - '0', s[idx + 1]);
        dfs(idx + 4, cal(cur, bra, op));
    }
    dfs(idx + 2, cal(cur, s[idx] - '0', op));
}

int main()
{
    cin >> n >> s;
    dfs(0, 0);
    cout << ans;
}