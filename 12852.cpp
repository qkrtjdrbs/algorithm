#include <bits/stdc++.h>
using namespace std;
int n, dp[1000001], order[1000001];

void go(int x){
    if(x == n) return;
    go(order[x]);
    cout << x << " ";
}

int main(){
    cin >> n;
    for(int i=n-1;i>=0;i--){
        dp[i] = 987654321;
        order[i] = i;
    }
    for(int i=n;i>=1;i--){
        if(i % 2 == 0){
            if(dp[i/2] > dp[i]+1){
                dp[i/2] = dp[i]+1;
                order[i/2] = i;
            }
        }
        if(i % 3 == 0){
            if(dp[i/3] > dp[i]+1){
                dp[i/3] = dp[i]+1;
                order[i/3] = i;
            }
        }
        if(dp[i-1] > dp[i]+1){
            dp[i-1] = dp[i]+1;
            order[i-1] = i;
        }
    }
    cout << dp[1] << '\n';
    cout << n << " ";
    go(1);
}