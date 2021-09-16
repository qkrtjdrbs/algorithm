#include <bits/stdc++.h>
using namespace std;
int n, k, c[101], d[2][10];

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> k;
    memset(d, 0, sizeof(d));
    for(int i=0;i<n;i++){
        cin >> c[i];
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=k;j++){
            if(j < c[i]) continue;
            if(j == c[j]) {
                d[1][j] = 1;
                continue;
            }
            d[1][j] = min(d[0][j-c[i]]+1, d[1][j]);
            d[0][j] = min(d[0][j-c[i]], d[1][j-c[i]]);
        }
    }
    int ans = min(d[0][k], d[1][k]);
    ans == 0 ? cout << -1 : cout << ans;
}

