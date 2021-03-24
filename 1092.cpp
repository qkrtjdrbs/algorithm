#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr_n[51];
vector <int> arr_m;
int n, m, result;

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr_n[i];
	cin >> m;
	int num = 0;
	for (int i = 0; i < m; i++) {
		cin >> num;
		arr_m.push_back(num);
	}
	sort(arr_n, arr_n + n, cmp);
	sort(arr_m.begin(), arr_m.end(), cmp);
	if (arr_n[0] < arr_m[0]) {
		cout << -1 << endl;
		return 0;
	}
	while (arr_m.size()) {
		result++;
		for (int i = 0; i < n; i++) {			
			for (int j = 0; j < arr_m.size(); j++) {
				if (arr_n[i] >= arr_m[j]) {
					arr_m.erase(arr_m.begin() + j);
					break;
				}
			}
		}			
	}
	cout << result;
}