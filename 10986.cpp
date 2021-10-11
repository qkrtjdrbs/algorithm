#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
ll sum, ans, cnt[1001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
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
    cout << ans;
}