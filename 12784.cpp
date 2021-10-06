#include <bits/stdc++.h>
using namespace std;

int t, n, m, dp[1001];
vector<pair<int, int>> adj[1001];

int go(int cur, int prev){
    int &res = dp[cur];
    if(res != -1) return res;
    int cnt = 0;
    res = 0;
    for(auto next : adj[cur]){
        int nx, nc;
        tie(nx, nc) = next;
        if(nx != prev) {
            res += min(nc, go(nx, cur));
            cnt++;
        }
    }
    if(!cnt) res = 20001;
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        for(int i=1;i<=1000;i++) adj[i].clear();
        cin >> n >> m;
        if(n == 1){
            cout << 0 << '\n';
            continue;
        }
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
            adj[b].push_back({a, c});
        }
        cout << go(1, 0) << '\n';
    }
}