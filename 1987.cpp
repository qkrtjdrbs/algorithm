#include <iostream>
#include <algorithm>
using namespace std;
int r, c, ans = 0;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool check[26];
char b[20][20];
void go(int x, int y, int cnt)
{
    ans = max(ans, cnt);
    for (int k = 0; k < 4; k++)
    {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (0 <= nx && nx < r && 0 <= ny && ny < c)
        {
            if (!check[b[nx][ny] - 'A'])
            {
                check[b[nx][ny] - 'A'] = true;
                go(nx, ny, cnt + 1);
                check[b[nx][ny] - 'A'] = false;
            }
        }
    }
}
int main()
{
    cin >> r >> c;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> b[i][j];
    }
    check[b[0][0] - 'A'] = true;
    go(0, 0, 1);
    cout << ans;
}