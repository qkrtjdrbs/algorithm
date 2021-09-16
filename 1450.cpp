#include <bits/stdc++.h>
using namespace std;

int n, c, ans, a[33];
vector<int> v1, v2;

void dfs(int s, int e, int sum, vector<int>& v) {
	if (sum > c) return;
	if (s > e) return v.push_back(sum);
	dfs(s + 1, e, sum, v);
	dfs(s + 1, e, sum + a[s], v);
}

int main() {
	scanf("%d %d", &n, &c);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	dfs(0, n / 2 - 1, 0, v1); sort(v1.begin(), v1.end());
	dfs(n / 2, n - 1, 0, v2); sort(v2.begin(), v2.end());
	
	int e = v2.size() - 1;
	for (int s = 0; s < v1.size(); s++) {
		while (e >= 0 && v1[s] + v2[e] > c) e--;
		ans += e + 1;
	}
	printf("%d", ans);

	return 0;
}