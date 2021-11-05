#include <bits/stdc++.h>
using namespace std;

int t, n, m, k, dist[101][10001];
vector<tuple<int, int, int>> adj[101];

void init(){
    for(int i=0;i<=100;i++){
        adj[i].clear();
        for(int j=0;j<=10000;j++) dist[i][j] = 987654321;
    }
}

int dijk(){
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 1, 0});
    dist[1][0] = 0;
    while(!pq.empty()){
        int d, x, cost;
        tie(d, x, cost) = pq.top();
        pq.pop();
        d = -d;
        if(dist[x][cost] < d) continue;
        for(auto next : adj[x]){
            int nx, nc, nd;
            tie(nx, nc, nd) = next;
            nd += d;
            nc += cost;
            if(nc <= m && dist[nx][nc] > nd){
                dist[nx][nc] = nd;
                pq.push({-nd, nx, nc});
            }
        }
    }
    int res = 987654321;
    for(int i=0;i<=m;i++){
        res = min(res, dist[n][i]);
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> t;
    while(t--){
        init();
        cin >> n >> m >> k;
        for(int i=0;i<k;i++){
            int a, b, c, d;
            cin >> a >> b >> c >> d;
            adj[a].push_back({b, c, d});
        }
        int ans = dijk();
        ans == 987654321 ? cout << "Poor KCM\n" : cout << ans << '\n';
    }
}