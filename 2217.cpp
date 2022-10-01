#include <bits/stdc++.h>
using namespace std;

int n, arr[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    sort(arr, arr+n);
    int ans = 0;
    for(int i=0;i<n;i++){
        int res = arr[i]*(n-i);
        ans = max(ans, res);
    }
    cout << ans;
}