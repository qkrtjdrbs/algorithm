#include <bits/stdc++.h>
using namespace std;

int n, card[1001], dp[1001][1001];

int go(int turn, int l, int r){
    if(turn == n || l > r) return 0;
    int who = turn % 2;
    int &res = dp[l][r];
    if(res != -1) return res;
    if(!who) return res = max(card[l] + go(turn+1, l+1, r), card[r] + go(turn+1, l, r-1));
    return res = min(go(turn+1, l+1, r), go(turn+1, l, r-1));
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        memset(card, 0, sizeof(card));
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for(int i=0;i<n;i++) cin >> card[i];
        cout << go(0, 0, n-1) << '\n';
    }
}