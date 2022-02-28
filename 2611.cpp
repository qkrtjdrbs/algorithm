#include <bits/stdc++.h>
using namespace std;

int n, m, dp[1001], parent[1001];
vector<pair<int, int>> adj[1001];

int go(int x, bool first){
    if(!first && x == 1) return 0;
    int &res = dp[x];
    if(res != -1) return res;
    res = 0;
    for(auto next : adj[x]){
        auto [nx, cost] = next;
        int nc = cost + go(nx, 0);
        if(res < nc){
            res = nc;
            parent[x] = nx;
        }
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    memset(dp, -1, sizeof(dp));
    cout << go(1, 1) << '\n';
    int cnt = 0;
    for(int i=1;i!=parent[i];i=parent[i]){
        if(cnt == 2) break;
        cout << i << " ";
        if(i == 1) cnt++;
    }
}