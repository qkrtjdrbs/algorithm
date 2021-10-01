#include <bits/stdc++.h>
using namespace std;

int n, m, psum[101][101], ans;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            scanf("%1d", &psum[i][j]);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            int second = psum[i][m] - psum[i][j];
            int third = psum[n][m] - psum[i][m];
            if(second && third) ans = max(ans, psum[i][j]*second*third);
            second = psum[n][j] - psum[i][j];
            third = psum[n][m] - psum[n][j];
            if(second && third) ans = max(ans, psum[i][j]*second*third);
        }
    }
    cout << ans;
}