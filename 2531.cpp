#include <bits/stdc++.h>
using namespace std;

int n, d, k, c, sushi[3000001], check[3001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> d >> k >> c;
    int ans = 0;
    for(int i=0;i<n;i++) {
        cin >> sushi[i];
    }
    for(int i=0;i<k;i++){
        ans += (check[sushi[i]]++ == 0);
    }
    ans += (check[c]++ == 0);
    int l = 0, r = k - 1, res = ans;
    while(l < n){
        ans = max(res, ans);
        res -= (--check[sushi[l++]] == 0);
        r++;
        r %= n;
        res += (check[sushi[r]]++ == 0);
    }
    cout << ans;
}