#include <iostream>
#include <cstdlib>
#include <tuple>
#include <queue>
using namespace std;
int n, l, r, a[51][51], visit[51][51], cnt;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
bool open = false;

void init()
{
    open = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            visit[i][j] = 0;
    }
}

bool bfs(int x, int y)
{
    bool flag = false;
    queue<pair<int, int>> q;
    queue<pair<int, int>> p;
    q.push({x, y});
    p.push({x, y});
    int sum = a[x][y];
    while (!q.empty())
    {
        int fx, fy, sx, sy;
        tie(fx, fy) = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            visit[fx][fy] = 1;
            sx = fx + dx[i];
            sy = fy + dy[i];
            if (0 <= sx && sx < n && 0 <= sy && sy < n)
            {
                int diff = abs(a[sx][sy] - a[fx][fy]);
                if (!visit[sx][sy] && l <= diff && diff <= r)
                {
                    visit[sx][sy] = 1;
                    q.push({sx, sy});
                    p.push({sx, sy});
                    sum += a[sx][sy];
                    flag = true;
                }
            }
        }
    }

    int avg = sum / p.size();
    while (!p.empty())
    {
        int px, py;
        tie(px, py) = p.front();
        p.pop();
        a[px][py] = avg;
    }

    return flag;
}

int main()
{
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    }
    while (1)
    {
        bool flag;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!visit[i][j])
                    flag = bfs(i, j);
                if (flag)
                {
                    open = true;
                }
            }
        }
        if (open)
        {
            init();
            cnt += 1;
            continue;
        }
        else
        {
            cout << cnt;
            return 0;
        }
    }
}