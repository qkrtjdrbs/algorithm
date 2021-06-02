#include <iostream>
#include <algorithm>
using namespace std;
int n, a[100001][3], dp[2][3], MAX, MIN;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            cin >> a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            dp[1][j] = a[i][j];
            if(j == 0){
                dp[1][j] += max(dp[0][j], dp[0][j+1]);
            } else if(j == 1){
                dp[1][j] += max(dp[0][j-1], max(dp[0][j], dp[0][j+1]));
            } else{
                dp[1][j] += max(dp[0][j-1], dp[0][j]);
            }
        }
        for(int j=0;j<3;j++){
            dp[0][j] = dp[1][j];
        }
    }
    for(int j=0;j<3;j++){
        MAX = max(MAX, dp[0][j]);
    }
    for(int j=0;j<3;j++){
        dp[0][j] = 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            dp[1][j] = a[i][j];
            if(j == 0){
                dp[1][j] += min(dp[0][j], dp[0][j+1]);
            } else if(j == 1){
                dp[1][j] += min(dp[0][j-1], min(dp[0][j], dp[0][j+1]));
            } else{
                dp[1][j] += min(dp[0][j-1], dp[0][j]);
            }
        }
        for(int j=0;j<3;j++){
            dp[0][j] = dp[1][j];
        }
    }
    MIN = dp[0][0];
    for(int j=0;j<3;j++){
        MIN = min(MIN, dp[0][j]);
    }
    cout << MAX << " " << MIN;
}