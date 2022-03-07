#include <bits/stdc++.h>
using namespace std;

int n, psum[401][801];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    for(int t=1;;t++){
        cin >> n;
        if(!n) break;
        memset(psum, 0, sizeof(psum));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2*i-1;j++){
                cin >> psum[i][j];
                psum[i][j] += psum[i][j-1];
            }
        }
        int ans = -987654321;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=2*i-1;j+=2){
                int sum = 0;
                for(int k=0;k<=n-i;k++){
                    sum += psum[k+i][j+2*k] - psum[k+i][j-1];
                    ans = max(ans, sum);
                }
            }
        }
        for(int i=n;i>=1;i--){
            for(int j=2;j<=2*i-1;j+=2){
                int sum = 0;
                for(int k=0;;k++){
                    if(j-2*k-1 <= 0 || 2*(i-k)-1 < j) break;
                    sum +=  psum[i-k][j] - psum[i-k][j-2*k-1];
                    ans = max(ans, sum);
                }
            }
        }
        cout << t << ". " << ans << '\n';
    }
}