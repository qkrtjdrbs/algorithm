#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int t, n, visit[300][300], endx, endy;
int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    visit[x][y] = 0;
    while (!q.empty())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for (int k = 0; k < 8; k++)
        {
            int go_x = x + dx[k];
            int go_y = y + dy[k];
            if (go_x >= 0 && go_x < n && go_y >= 0 && go_y < n)
            {
                if (visit[go_x][go_y] == -1)
                {
                    q.push({go_x, go_y});
                    visit[go_x][go_y] = visit[x][y] + 1;
                }
            }
        } 
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        int startx, starty;
        cin >> n;
        cin >> startx >> starty;
        cin >> endx >> endy;
        memset(visit, -1, sizeof(visit));
        bfs(startx, starty);
        cout << visit[endx][endy] << '\n';
    }
}