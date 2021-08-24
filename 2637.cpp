#include <bits/stdc++.h>
using namespace std;

int n, m, dp[101];
bool indegree[101];
vector<pair<int, int>> adj[101];
vector<int> ans;

int dfs(int x){
    if(dp[x] != -1) return dp[x];
    if(x == n) return 1;
    int &res = dp[x];
    res = 0;
    for(auto next : adj[x]){
        int nx, cost;
        tie(nx, cost) = next;
        res += dfs(nx)*cost;
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios_base::sync_with_stdio(0);
    cin >> n >> m;
    memset(dp, -1, sizeof(dp));
    for(int i=0;i<m;i++){
        int x, y, k;
        cin >> x >> y >> k;
        indegree[x] = true;
        adj[y].push_back({x, k});
    }
    for(int i=1;i<n;i++){
        if(!indegree[i]){
            ans.push_back(i);
            cout << i << " " << dfs(i) << '\n';
        }
    }
}