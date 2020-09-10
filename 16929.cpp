#include <iostream>
#include <cstring>
using namespace std;
int n, m;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int dist[55][55];
char a[55][55];
bool visit[55][55], flag;
bool dfs(int x, int y, char color, int cnt)
{
    if (visit[x][y])
    {
        if (cnt - dist[x][y] >= 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    visit[x][y] = true;
    dist[x][y] = cnt;
    int nx, ny;
    for (int k = 0; k < 4; k++)
    {
        nx = x + dx[k];
        ny = y + dy[k];
        if (0 <= nx && nx < n && 0 <= ny && ny < m)
        {
            if (a[nx][ny] == color)
            {
                if (dfs(nx, ny, color, cnt + 1))
                    return true;
            }
        }
    }
    return false;
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (visit[i][j])
                continue;
            memset(dist, 0, sizeof(dist));
            flag = dfs(i, j, a[i][j], 1);
            if (flag)
            {
                printf("Yes");
                return 0;
            }
        }
    }
    printf("No");
}