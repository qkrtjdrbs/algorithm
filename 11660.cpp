#include <iostream>
#include <algorithm>
using namespace std;
int psum[1025][1025];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N, M, num;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> num;
			psum[i + 1][j + 1] = psum[i][j + 1] + psum[i + 1][j] - psum[i][j] + num;
		}
	}
	for (int i = 0; i < M; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1] << '\n';
	}
	return 0;
}