#include <bits/stdc++.h>
using namespace std;

int n, a[51], b[51];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];

    sort(a, a+n);
    sort(b, b+n);
    reverse(b, b+n);

    int ans = 0;
    for(int i=0;i<n;i++) ans += (a[i]*b[i]);
    cout << ans;
}