#include <bits/stdc++.h>
using namespace std;

int n, arr[100002], psum[100002], rpsum[100002];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }
    for(int i=n;i>0;i--){
        rpsum[i] = rpsum[i+1] + arr[i];
    }
    int ans=0;
    // 벌통 오른쪽 끝
    for(int i=2;i<n;i++){
        int res = psum[n]-psum[1] + psum[n]-psum[i] - arr[i];
        ans = max(ans, res);
    }
    // 벌통 왼쪽 끝
    for(int i=n-1;i>0;i--){
        int res = rpsum[1]-rpsum[n] + rpsum[1]-rpsum[i] - arr[i];
        ans = max(ans, res);
    }
    // 벌통 가운데
    for(int i=2;i<n;i++){
        int res = psum[i]-psum[1] + rpsum[i]-rpsum[n];
        ans = max(ans, res);
    }
    cout << ans;
}