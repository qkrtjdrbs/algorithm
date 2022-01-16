#include <bits/stdc++.h>
using namespace std;

int n, m, height[5001], dp[5001];
vector<int> adj[5001];

int go(int cur){
    int &res = dp[cur];
    if(res != -1) return res;

    res = 1;
    for(auto next : adj[cur]){
        if(height[next] < height[cur]) continue;
        res = max(res, 1+go(next));
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> height[i];
    }
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(dp, -1, sizeof(dp));
    for(int i=1;i<=n;i++){
        cout << go(i) << '\n';
    }
}