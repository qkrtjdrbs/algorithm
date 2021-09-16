#include <bits/stdc++.h>
#define MAX 1004001
using namespace std;
int n, a[MAX];

bool isPalin(int n) {
	string str = to_string(n);
	for (int i = 0; i < str.size() / 2; i++) {
		if (str[i] != str[str.size() - i - 1])
			return false;
	}
	return true;
}

int main(){
    cin >> n;
    a[1] = 1;
    for (int i = 2; i <= MAX; i++) { 
        if (a[i] == 1)
            continue;
        for (int j = i + i; j <= MAX; j += i) {
            a[j] = 1;
        }
    }
    for (int i = n; i <= MAX; i++) {
        if(a[i] == 0){
            if(isPalin(i)){
                cout << i;
                break;
            }
        }
    }
}