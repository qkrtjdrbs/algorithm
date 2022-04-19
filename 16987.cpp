#include <bits/stdc++.h>
using namespace std;

int n, ans, s[9], w[9];

void go(int idx, int cnt){
    ans = max(ans, cnt);
    if(idx > n) return;
    if(s[idx] <= 0){
        go(idx+1, cnt);
        return;
    }
    for(int j=1;j<=n;j++){
        if(idx == j) continue;
        if(s[j] <= 0) continue;
        s[idx] -= w[j];
        s[j] -= w[idx];
        if(s[idx] <= 0 && s[j] <= 0) go(idx+1, cnt+2);
        else if(s[idx] >= 0 && s[j] <= 0) go(idx+1, cnt+1);
        else if(s[idx] <= 0 && s[j] >= 0) go(idx+1, cnt+1);
        else if(s[idx] >= 0 && s[j] >= 0) go(idx+1, cnt);
        s[idx] += w[j];
        s[j] += w[idx];
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> s[i] >> w[i];
    }
    go(1, 0);
    cout << ans;
}