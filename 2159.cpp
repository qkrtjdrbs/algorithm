#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
ll dist[100002][5];
vector<pair<int, int>> pos;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
 
int main() {
	ll n, sx, sy, ex, ey;
	cin >> n;
	cin >> sx >> sy;
	for (int i = 0; i < n; i++) {
		cin >> ex >> ey;
		pos.push_back({ex, ey});
	}
	for (int i = 0; i < 4; i++) {
		int nx = pos[0].first + dx[i];
		int ny = pos[0].second + dy[i];
		dist[0][i] = abs(nx - sx) + abs(ny - sy);
	}
	for (int i = 1; i < n; i++) {
		int x = pos[i].first;
		int y = pos[i].second;
		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];
			ll temp = LLONG_MAX;
			for (int j = 0; j < 4; j++) {
				ll px = pos[i - 1].first + dx[j];
				ll py = pos[i - 1].second + dy[j];
				temp = min(temp, dist[i - 1][j] + abs(nx - px) + abs(ny - py));
			}
			dist[i][k] = temp;
		}
	}
	ll ans = LLONG_MAX;
	for (int i = 0; i < 4; i++) {
		ans = min(ans, dist[n - 1][i]);
	}
	cout << ans << "\n";
}