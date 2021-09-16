#include <bits/stdc++.h>
using namespace std;

int n, x, a[1000001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> x;
    sort(a, a+n);
    int l = 0, r = n-1, ans = 0;
    while(l < r){
        int sum = a[l] + a[r];
        if(sum < x) l++;
        else if(sum > x) r--;
        else {
            ans++;
            l++; r--;
        }
    }
    cout << ans;
}