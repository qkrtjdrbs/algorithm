#include <bits/stdc++.h>
using namespace std;

int n, psum[100001], dp[300001];
string s;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    s = "X" + s;
    memset(dp, -1, sizeof(dp));
    int ans = 0, cnt = 0;
    dp[100000] = 0;
    for(int i=1;i<=n;i++){
        if(s[i] == 'S'){
            cnt += 2;
            psum[i] = 1;
        } else if(s[i] == 'K') {
            cnt -= 1;
            psum[i] = 1;
        }
        psum[i] += psum[i-1];
        int offset = cnt+100000;
        if(dp[offset] == -1) dp[offset] = i;
        else if(psum[i] - psum[dp[offset]] > 0){
            ans = max(ans, i-dp[offset]);
        }
    }
    cout << (ans == 0 ? -1 : ans);
}