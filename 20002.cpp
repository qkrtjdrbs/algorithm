#include <bits/stdc++.h>
using namespace std;

int n, ans=-987654321, psum[301][301];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> psum[i][j];
            psum[i][j] += psum[i-1][j] + psum[i][j-1] - psum[i-1][j-1];
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                int ii=i+k-1, jj=j+k-1;
                if(ii > n || jj > n) continue;
                ans = max(ans, psum[ii][jj]-psum[i-1][jj]-psum[ii][j-1]+psum[i-1][j-1]);
            }
        }
    }
    cout << ans;
}