#include <iostream>
#include <algorithm>
using namespace std;
int n, m, x1, y_1, x2, y2, ans;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
char b[21][21];
bool flag;
void go(int x1, int y_1, int x2, int y2, int cnt)
{
    if (cnt > 10)
        return;
    bool flag1 = true;
    bool flag2 = true;
    if (x1 < 0 || n <= x1 || y_1 < 0 || m <= y_1)
        flag1 = false;
    if (x2 < 0 || n <= x2 || y2 < 0 || m <= y2)
        flag2 = false;
    if (!flag1 && !flag2)
        return;
    if (!flag1 || !flag2)
    {
        if (ans == 0)
            ans = cnt;
        else
        {
            ans = min(ans, cnt);
            return;
        }
    }
    for (int k = 0; k < 4; k++)
    {
        int nx1 = x1 + dx[k];
        int ny1 = y_1 + dy[k];
        int nx2 = x2 + dx[k];
        int ny2 = y2 + dy[k];
        if (b[nx1][ny1] == '#')
        {
            nx1 = x1;
            ny1 = y_1;
        }
        if (b[nx2][ny2] == '#')
        {
            nx2 = x2;
            ny2 = y2;
        }
        go(nx1, ny1, nx2, ny2, cnt + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
            if (b[i][j] == 'o' && !flag)
            {
                x1 = i;
                y_1 = j;
                b[i][j] = '.';
                flag = true;
            }
            if (b[i][j] == 'o' && flag)
            {
                x2 = i;
                y2 = j;
                b[i][j] = '.';
            }
        }
    }
    go(x1, y_1, x2, y2, 0);
    if (ans == 0)
    {
        cout << -1;
        return 0;
    }
    cout << ans;
}