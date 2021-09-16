#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int n, m, start, visit[1001];
vector<int> adjList[1001];

void init()
{
    for (int i = 0; i < 1001; i++)
        visit[i] = 0;
    cout << '\n';
}

void DFS(int v)
{
    cout << v << " ";
    visit[v] = 1;
    for (auto i : adjList[v])
    {
        if (!visit[i])
        {
            DFS(i);
        }
    }
}

void BFS(int start)
{
    queue<int> q;
    q.push(start);
    visit[start] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        cout << v << " ";
        for (auto i : adjList[v])
        {
            if (!visit[i])
            {
                visit[i] = 1;
                q.push(i);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> start;
    for (int i = 0; i < m; i++)
    {
        int v1, v2;
        cin >> v1 >> v2;
        adjList[v1].push_back(v2);
        adjList[v2].push_back(v1);
    }
    for (int i = 0; i < 1001; i++)
        sort(adjList[i].begin(), adjList[i].end());
    DFS(start);
    init();
    BFS(start);
}