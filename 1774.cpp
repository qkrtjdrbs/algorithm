#include <bits/stdc++.h>
using namespace std;
int n, m, p[1001],cnt;
double res;
typedef pair<double,pair<int, int>> P;
vector<pair<int, int>> v;
priority_queue<P, vector<P>, greater<P>> pq;

int find(int x) {
	if (p[x] < 0) return x;
	return p[x] = find(p[x]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[a] = b;
	return true;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);
	cin >> n >> m;
	memset(p, -1, sizeof(p));
	int a, b;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double t = sqrt(pow(v[i].first - v[j].first, 2)+pow(v[i].second-v[j].second,2));
			pq.push({ t,{i,j} });
		}
	}
	for (int j = 0; j < m; j++) {
		cin >> a >> b;
		merge(a - 1, b - 1);
	}
	while (!pq.empty()) {
		double cost = pq.top().first;
		int a = pq.top().second.first;
		int b = pq.top().second.second;
		pq.pop();
		if (merge(a, b)) {
			cnt++;
			res += cost;
			if (cnt == n - 1) break;
		}
	}
	cout <<fixed<<setprecision(2)<< res << '\n';
	return 0;
}