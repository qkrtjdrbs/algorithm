#include <bits/stdc++.h>
using namespace std;

int n, k, arr[1000001], psum[1000001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> k;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        psum[i] = (arr[i] % 2);
    }
    for(int i=1;i<=n;i++){
        psum[i] += psum[i-1];
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        if(arr[i] % 2 == 0){
            int l=i, r=i;
            while(l <= r && r <= n){
                if(k < psum[r] - psum[l-1]){
                    l++;
                } else {
                    ans = max(ans, (r-l+1)-(psum[r]-psum[l-1]));
                    r++;
                }
            }
            i = max(l, r);
        }
    }
    cout << ans;
}