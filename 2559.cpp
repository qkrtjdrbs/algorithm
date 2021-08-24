#include <bits/stdc++.h>
using namespace std;

int n, k, ans, arr[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=0;i<n;i++) cin >> arr[i];
    for(int i=0;i<k;i++) ans += arr[i];
    int l = 0, r = k, res = ans;
    while(r < n){
        res -= arr[l++];
        res += arr[r++];
        ans = max(ans, res);
    }   
    cout << ans;
}