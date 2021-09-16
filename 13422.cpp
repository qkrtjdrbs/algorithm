#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, home[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        memset(home, 0, sizeof(home));
        cin >> n >> m >> k;
        for(int i=0;i<n;i++) cin >> home[i];
        
        int sum = 0;
        for(int i=0;i<m;i++) sum += home[i];

        int l = 0, r = m-1, ans = (sum < k);
        if(n == m) {
            cout << ans << '\n';
            continue;
        }
        while(l < n-1){
            sum -= home[l++];
            r++;
            r %= n;
            sum += home[r];
            if(sum < k) ans++;
        }
        cout << ans << '\n';
    }
}