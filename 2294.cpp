#include <bits/stdc++.h>
using namespace std;
int n, k, coin[101], dp[10001];

int go(int sum, int cnt){
    if(sum == 0){
        return cnt;
    }
    if(dp[sum] == -1)
        dp[sum] = cnt;
    for(int i=0;i<n;i++){
        int next = sum - coin[i];
        if(next < 0)
            continue;
        dp[sum] = min(dp[sum], go(next, cnt+1));
    }
    return dp[sum];
}

int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> coin[i];
        dp[coin[i]];
    }
    cout << go(k, 0);
}