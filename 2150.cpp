#include <bits/stdc++.h>
using namespace std;

vector <int> v[10001], e[10001]; 
vector <int> res[10001]; 
bool visited[10001];

stack <int> st;

void dfs(int s) {
	visited[s] = 1;
	for (auto a : v[s]) {
		if (!visited[a]) dfs(a);
	}
	st.push(s); 
}

void redfs(int s,int t) {
	visited[s] = 1;
	res[t].push_back(s);
	for (auto a : e[s]) {
		if (!visited[a]) redfs(a,t);
	}
}
int main() {
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		e[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) { 
		if (!visited[i]) dfs(i); 
	}
	memset(visited, 0, sizeof(visited));
	int cnt = 0;
	while (!st.empty()) { 
		int s = st.top();
		st.pop();
		if (visited[s]) continue; 
		redfs(s,cnt);
		cnt++; 
	}
	cout << cnt << "\n";
	vector <pair<int, int>> r;
	for (int i = 0; i < cnt; i++) {
		sort(res[i].begin(), res[i].end()); 
		r.push_back({ res[i][0],i }); 
	}
	sort(r.begin(), r.end()); 
	for (auto a : r) { 
		for (auto b : res[a.second]) cout << b << " ";
		cout << -1 << "\n";
	}
}