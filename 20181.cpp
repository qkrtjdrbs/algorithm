#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k, arr[101];
ll dp[101];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    int l=0, r=0; ll sum=arr[0];
    while(l <= r){
        dp[r] = max(dp[r], dp[r-1]);
        if(sum < k){
            if(r+1 < n){
                sum += arr[++r];
            } else break;
        } else {
            dp[r] = max(dp[r], dp[l-1]+sum-k);
            sum -= arr[l++];
            if(l > r && r+1 < n) sum += arr[++r];
        }
    }
    cout << dp[n-1];
}