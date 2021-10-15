#include <bits/stdc++.h>
using namespace std;

int n, seq, psum[50001], dp[4][50001];

int go(int train, int num){
    if(train > 3 || num > n) return 0;
    int &res = dp[train][num];
    if(res != -1) return res;
    res = 0;
    res = max(go(train, num+1), psum[num] - psum[num-seq] + go(train+1, num+seq));
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    int sum = 0;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        sum += x;
        psum[i] = sum;
    }
    cin >> seq;
    cout << go(1, seq);
}