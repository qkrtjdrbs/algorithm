#include <bits/stdc++.h>
using namespace std;

int a, b, c;
bool visited[201][201][201];
set<int> ans;

void bfs()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, c});
    visited[0][0][c] = 1;
    while (!q.empty())
    {
        int x, y, z;
        tie(x, y, z) = q.front();
        q.pop();
        if (x == 0)
            ans.insert(z);
        int rx = a - x;
        int ry = b - y;
        int rz = c - z;
        if (ry >= x)
        {
            if (!visited[0][y+x][z])
            {
                q.push({0, y+x, z});
                visited[0][y+x][z] = 1;
            }
        }
        else
        {
            if (!visited[x-ry][b][z])
            {
                q.push({x - ry, b, z});
                visited[x-ry][b][z] = 1;
            }
        }
        if (rz >= x)
        {
            if (!visited[0][y][z+x])
            {
                q.push({0, y, z+x});
                visited[0][y][z+x] = 1;
            }
        }
        else
        {
            if (!visited[x-rz][y][c])
            {
                q.push({x - rz, y, c});
                visited[x-rz][y][c] = 1;
            }
        }
        if (rx >= y)
        {
            if (!visited[x+y][0][z])
            {
                q.push({x+y, 0, z});
                visited[x+y][0][z] = 1;
            }
        }
        else
        {
            if (!visited[a][y-rx][z])
            {
                q.push({a, y - rx, z});
                visited[a][y-rx][z] = 1;
            }
        }
        if (rz >= y)
        {
            if (!visited[x][0][z+y])
            {
                q.push({x, 0, z+y});
                visited[x][0][z+y] = 1;
            }
        }
        else
        {
            if (!visited[x][y-rz][c])
            {
                q.push({x, y - rz, c});
                visited[x][y-rz][c] = 1;
            }
        }
        if (rx >= z)
        {
            if (!visited[x+z][y][0])
            {
                q.push({x+z, y, 0});
                visited[x+z][y][0] = 1;
            }
        }
        else
        {
            if (!visited[a][y][z-rx])
            {
                q.push({a, y, z - rx});
                visited[a][y][z-rx] = 1;
            }
        }
        if (ry >= z)
        {
            if (!visited[x][y+z][0])
            {
                q.push({x, y+z, 0});
                visited[x][y+z][0] = 1;
            }
        }
        else
        {
            if (!visited[x][b][z-ry])
            {
                q.push({x, b, z - ry});
                visited[x][b][z-ry] = 1;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> a >> b >> c;
    bfs();
    for (auto i : ans)
        cout << i << " ";
}