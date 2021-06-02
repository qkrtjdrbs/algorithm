#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
int n, k, d[10001], coin[100];

int main(){
    cin >> n >> k;
    for(int i=0;i<=k;i++)
        d[i] = k;
    for(int i=0;i<n;i++){
        cin >> coin[i];
    }
    d[0] = 0; d[k] = k+1;
    for(int i=0;i<=k;i++){
        for(int j=0;j<n;j++){
            if(i >= coin[j])
                d[i] = min(d[i], d[i-coin[j]]+1);
        }
    }
    d[k] == k+1 ? d[k] = -1 : d[k];
    cout << d[k];
=======
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
>>>>>>> bcbfbf89b4bff10f8ab3106396e05a364e484f01
}