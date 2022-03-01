#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, psum[100001], dp[100001][5];

ll go(int x, int sum, int num){
    if(num == 4){
        if(psum[x] == sum * num) return 1;
        else return 0;
    }
    int &res = dp[x][num];
    if(res != -1) return res;
    res = 0;
    if(num == 3){
        res += go(n, sum, 4);
    } else {
        for(int i=x+1;i<n;i++){
            if(psum[i] == psum[x] + sum){    
                res += go(i, sum, num+1);      
            }
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> psum[i];
        psum[i] += psum[i-1];
    }
    if(!psum[n]) {
        ll ans = 0;
        for(int i=1;i<=n;i++) ans += !psum[i];
        cout << (ans-1)*(ans-2)*(ans-3)/6;
        return 0;
    }
    memset(dp, -1, sizeof(dp));
    ll ans = 0;
    for(int i=1;i<=n-3;i++){
        if(psum[n] / 4 == psum[i]) ans += go(i, psum[i], 1);
    }
    cout << ans;
}