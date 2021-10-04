#include <bits/stdc++.h>
using namespace std;

int n, m, q, psum[1001][1001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> psum[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int a, b, c, d, sum, cnt;
        cin >> a >> b >> c >> d;
        sum = psum[c][d] - psum[c][b-1] - psum[a-1][d] + psum[a-1][b-1];
        cnt = (c-a+1)*(d-b+1);
        cout << sum / cnt << '\n';
    }
}