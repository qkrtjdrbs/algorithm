#include <bits/stdc++.h>
using namespace std;
long long t, n, m, d[30][30];

int fib(int x, int y){
    if(d[x][y] != -1) return d[x][y];
    if(y == 0 || x == y) return 1;
    return d[x][y] = fib(x-1, y) + fib(x-1, y-1);
}

int main(){
    cin >> t;
    memset(d, -1, sizeof(d));
    while(t--){
        cin >> n >> m;
        int ans = fib(m, n);
        cout << ans << '\n';
    }
}