#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t, n, m;
ll cnt[1000001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        ll sum = 0, ans = 0;
        memset(cnt, 0, sizeof(cnt));
        cin >> m >> n;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            sum += x;
            cnt[sum % m]++;
        }
        ans += cnt[0];
        for(int i=0;i<m;i++){
            ans += cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << ans << '\n';
    }
}