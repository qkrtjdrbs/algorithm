#include <iostream>
#include <algorithm>
using namespace std;
int n, m[26][26], visit[26][26], num[26*26];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void dfs(int x, int y, int cnt)
{
    num[cnt]+=1;
    visit[x][y] = cnt;
    for (int i = 0; i < 4; i++)
    {
        int go_x = x + dx[i];
        int go_y = y + dy[i];
        if (go_x >= 0 && go_x < n && go_y >= 0 && go_y < n)
        {
            if (m[go_x][go_y] == 1 && visit[go_x][go_y] == 0)
            {
                dfs(go_x, go_y, cnt);
            }
        }
    }
}
int main()
{
    int cnt = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%1d", &m[i][j]);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (m[i][j] == 1 && visit[i][j] == 0)
            {
                 dfs(i, j, ++cnt);
            }
        }
    }
    sort(num+1, num+cnt+1);
    printf("%d\n", cnt);
    for(int i=1;i<=cnt;i++)
        printf("%d\n",num[i]);
}