#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int n, c[126][126], v[126][126], ans;
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

void bfs()
{
    priority_queue<tuple<int, int, int>> q;
    q.push({0, 0, -c[0][0]});
    while (!q.empty())
    {
        int x, y, cost;
        tie(x, y, cost) = q.top();
        q.pop();
        cost *= -1;
        for (int k = 0; k < 4; k++)
        {
            int nx = x + dx[k];
            int ny = y + dy[k];
            int nc = cost + c[nx][ny];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (v[nx][ny] > nc)
            {
                v[nx][ny] = nc;
                q.push({nx, ny, -nc});
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int problem = 1;
    while (1)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                v[i][j] = MAX;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                cin >> c[i][j];
        v[0][0] = c[0][0];
        bfs();
        cout << "Problem " << problem << ": " << v[n - 1][n - 1] << '\n';
        problem++;
    }
}