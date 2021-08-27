#include <bits/stdc++.h>
using namespace std;

int n, k, arr[1000001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    int l = 0, r = 0, cnt = (arr[l] == 1), ans = 987654321;
    while(l <= r && l < n && r < n){
        if(k == cnt) {
            ans = min(ans, r - l + 1);
            cnt -= (arr[l++] == 1);
        } else {
            if(r <= n-1){
                cnt += (arr[++r] == 1);
            } else break;
        }
    }
    ans == 987654321 ? cout << -1 : cout << ans;
}