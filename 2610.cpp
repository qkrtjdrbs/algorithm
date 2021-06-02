#include <bits/stdc++.h>
using namespace std;
int Map[101][101], parent[101];
vector<int> v[101];
vector<int> ans;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(x > y) parent[x] = y;
    else parent[y] = x; 
}

void floyd(int idx){
    int len = v[idx].size();
    int minRes = 987654321;
    int so;
    int res = 0;
    for (int k = 0; k < len; k++)
	{
		res = 0;
        for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				int ni = v[idx][i];
				int nj = v[idx][j];
				int nk = v[idx][k];
                res = max(res, max(Map[ni][nk], Map[nk][ni]));
			}
		}
        if(minRes > res){
            minRes = res;
            so = v[idx][k];
        }
	}
    ans.push_back(so);    
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        parent[i] = i;
        for (int j = 1; j <= n; j++)
        {
            if(i == j) Map[i][j] = 0;
            else Map[i][j] = 987654321;
        }
    }
	for (int i = 0; i < m; i++)
	{
		int a, b;
        cin >> a >> b;
        Union(a, b);
		Map[a][b] = 1;
		Map[b][a] = 1;
	}
    for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{	
                if (Map[i][j] > Map[i][k] + Map[k][j]){
					Map[i][j] = Map[i][k] + Map[k][j];
                }
             
			}
		}
	}
    for (int i = 1; i <= n; i++)
    {
        v[Find(i)].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if(!v[i].empty()){
            floyd(i);
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
	for(auto x : ans){
        cout << x << '\n';
    }
}