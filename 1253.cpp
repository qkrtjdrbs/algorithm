#include <bits/stdc++.h>
using namespace std;
int n, a[2001], ans;
multimap<int, int> m;

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a[i];
        m.insert({a[i], i});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i == j) continue;
            int num1 = a[j];
            int num2 = a[i] - a[j];
            if(m.count(num2) != 0){
                if(num2 == a[i]) {
                    if(a[i] == 0 && m.count(num2) <= 2) continue;
                    if(m.count(num2) == 1) continue;
                }
                if(num1 == num2) {
                    if(m.count(num1) == 1) continue;
                }
            }
            if(m.count(num1) != 0 && m.count(num2) != 0) {
                ++ans;
                break;
            }
        }
    }
    cout << ans;
}