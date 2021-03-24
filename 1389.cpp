#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int n, m, sum, minK = 987654321, ans, visit[101];
vector<int> adj[101];

void dfs(int start, int end, int cnt)
{
    queue<pair<int, int>> q;
    q.push({start, 0});
    while (!q.empty())
    {
        int x = q.front().first;
        int cnts = q.front().second;
        q.pop();
        if (x == end)
        {
            sum += cnts;
            return;
        }
        visit[x] = 1;
        for (int i : adj[x])
        {
            if (!visit[i])
                q.push({i, cnts + 1});
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++)
    {
        sum = 0;
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            visit[i] = 1;
            dfs(i, j, 0);
            for(int k=0;k<=n;k++)
                visit[k]=0;
        }
        if (sum < minK)
        {
            minK = sum;
            ans = i;
        }
    }
    cout << ans;
}