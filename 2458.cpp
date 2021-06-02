#include <bits/stdc++.h>
using namespace std;
int Map[501][501];

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m, a, b;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		Map[a][b] = 1;
	}
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (Map[i][k] && Map[k][j])
					Map[i][j] = 1;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j)continue;
			if (Map[i][j] == 0 && Map[j][i] == 0)
				cnt++;
		}
		if (cnt == 0) ans++;
	}
	cout << ans << '\n';
}