#include <bits/stdc++.h>
using namespace std;

int n, m, K, psum[1001][1001][3];
string Map[1001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    cin >> K;
    for(int i=0;i<n;i++) cin >> Map[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(Map[i][j] == 'J') psum[i+1][j+1][0]++;
            else if(Map[i][j] == 'O') psum[i+1][j+1][1]++;
            else psum[i+1][j+1][2]++;
        }
    }
    for(int k=0;k<3;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                psum[i][j][k] += psum[i-1][j][k] + psum[i][j-1][k] - psum[i-1][j-1][k];
            }
        }
    }
    for(int i=0;i<K;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        for(int j=0;j<3;j++){
            cout << psum[c][d][j] - psum[c][b-1][j] - psum[a-1][d][j] + psum[a-1][b-1][j] << " ";
        }
        cout << '\n';
    }
}