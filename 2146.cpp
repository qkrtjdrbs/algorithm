#include <bits/stdc++.h>
using namespace std;
int n, Map[101][101], Visit[101][101], ans = 987654321;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
vector<pair<int, int>> com;

void initVisit()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Visit[i][j] = 0;
        }
    }
}

void findRoute(int loc)
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Map[i][j] == loc)
            {
                Visit[i][j] = 1;
                q.push({i, j});
            }
        }
    }
    while (!q.empty())
    {   
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nextY = y + dy[i];
            int nextX = x + dx[i];
            if (0 <= nextY && nextY < n && 0 <= nextX && nextX < n)
            {
                if (Map[nextY][nextX] && Map[nextY][nextX] != loc)
                    ans = min(ans, Visit[y][x]);
                else if (!Map[nextY][nextX] && !Visit[nextY][nextX])
                {
                    Visit[nextY][nextX] = Visit[y][x] + 1;
                    q.push(make_pair(nextY, nextX));
                }
            }
        }
    }
}


void dfs(int sx, int sy, int cnt)
{
    Map[sx][sy] = cnt;
    Visit[sx][sy] = 1;
    for (int k = 0; k < 4; k++)
    {
        int nx = sx + dx[k];
        int ny = sy + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
            continue;
        if (!Visit[nx][ny] && Map[nx][ny])
        {
            dfs(nx, ny, cnt);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> Map[i][j];
    }
    int cnt = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (Map[i][j] && !Visit[i][j])
            {
                dfs(i, j, cnt++);
            }
        }
    }
    for(int i=1;i<cnt;i++){
        initVisit();
        findRoute(i);
    }
    cout << ans;
}