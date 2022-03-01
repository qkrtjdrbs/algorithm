#include <bits/stdc++.h>
using namespace std;

int n, psum[100001][2], dp[100001];
string s;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> s;
    n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == 'S') psum[i][0]++;
        else if(s[i] == 'K') psum[i][1]++;
        psum[i][0] += psum[i-1][0];
        psum[i][1] += psum[i-1][1];
    }
    dp[2] = psum[2][0] * 2 == psum[2][1] ? 3 : 0;
    int ans = max(0, dp[2]);
    for(int i=3;i<n;i++){
        if(s[i] != 'S' && s[i] != 'K') dp[i] = max(dp[i-1]+1, dp[i]);

        ans = max(ans, dp[i]);
    }
    cout << ans;
}