#include <bits/stdc++.h>
using namespace std;

int n, m, arr[100001], psum[100001], dp[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }
    dp[m] = psum[m];
    int ans = max(0, dp[m]);
    for(int i=m+1;i<=n;i++){
        dp[i] = max(dp[i-1]+arr[i], psum[i]-psum[i-m]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}