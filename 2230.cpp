#include <bits/stdc++.h>
using namespace std;

int n, m, ans=2000000000, a[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    if(!m){
        cout << 0;
        return 0;
    }
    for(int i=0;i<n;i++) cin >> a[i];
    sort(a, a+n);
    int i = 0, j = 0;
    while(i <= j && i < n && j < n){
        int gap = a[j] - a[i];
        if(gap < m) j++;
        else if(gap >= m) {
            ans = min(ans, gap);
            i++;
        }
    }
    cout << ans;
}   