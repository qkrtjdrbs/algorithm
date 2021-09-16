#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
	int T,N;
	cin >> T;
	for (int t=0;t<T;t++) {
		cin >> N;
		vector<int> parent(10001, 0);
		for (int n=0;n<N-1;n++) {
			int A, B;
			cin >> A >> B;
			parent[B] = A;
		}
		int a, b;
		cin >> a >> b;
        set<int> s;
		int now = a;
		while (now != 0) {
			s.insert(now);
			now = parent[now];
		}
		now = b;
		while (now != 0) {
			if(s.find(now) != s.end()){
                cout << now << '\n';
                break;
            }
			now = parent[now];
		}
	}
}