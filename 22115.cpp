#include <bits/stdc++.h>
using namespace std;
int n, k, c[101], dp[100001];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;
    if(k == 0){
        cout << 0;
        return 0;
    }
    for(int i=1;i<=k;i++)
        dp[i] = k;
    for(int i=1;i<=n;i++){
        cin >> c[i];
    }
    dp[0] = 0; dp[k] = k+1;
    for(int i=1;i<=n;i++){
        for(int j=k;j>=0;j--){
            if(j - c[i] < 0) break;
            dp[j] = min(dp[j], dp[j-c[i]] + 1);
        }
    }
    dp[k] == k+1 ? cout << -1 : cout << dp[k];
}