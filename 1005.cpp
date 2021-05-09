#include <bits/stdc++.h>
using namespace std;
int t, n, k, dp[1001], d[1001];
vector<int> w[1001];

int dfs(int idx){
    if(dp[idx] != -1) return dp[idx];
    dp[idx] = 0;
    int &res = dp[idx];
    for(auto i : w[idx]){
        res = max(res, dfs(i));  
    }
    res += d[idx];
    return res;
}

void init(){
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        w[i].clear();
        d[i] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    while(t--){
        init();
        int start;
        cin >> n >> k;
        for(int i=1;i<=n;i++){
            cin >> d[i];
        }
        for(int i=1;i<=k;i++){
            int end, start;
            cin >> start >> end;
            w[end].push_back({start});
        }
        cin >> start;
        int ans = dfs(start);
        cout << ans << '\n';
    }
}