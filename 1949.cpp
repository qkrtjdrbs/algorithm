#include <bits/stdc++.h>
using namespace std;

int n, pop[10001], dp[10001][2];
vector<int> adj[10001];

int go(int cur, bool sel, int prev){
    int &res = dp[cur][sel];
    if(res != -1) return res;
    res = sel*pop[cur];
    if(sel){
        for(auto next : adj[cur]){
            if(next != prev){
                res += go(next, !sel, cur);
            }
        }
    } else {
        for(auto next : adj[cur]){
            if(next != prev){
                res += max(go(next, sel, cur), go(next, !sel, cur));
            }
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i=1;i<=n;i++) cin >> pop[i];
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int ans = max(go(1, 0, -1), go(1, 1, -1));
    cout << ans;
}