#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int t, n, m, a[20001], b[20001];
    cin >> t;
    while(t--){
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        cin >> n >> m;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int j=0;j<m;j++) cin >> b[j];
        sort(a, a+n);
        sort(b, b+m);
        int i = n-1, j = m-1, ans = 0;
        while(i >= 0 && j >= 0){
            if(a[i] > b[j]){
                ans += j + 1;
                i--;
            } else {
                j--;
            }
        }
        cout << ans << '\n';
    }
}