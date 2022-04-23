#include <bits/stdc++.h>
using namespace std;

int n, m, s, t, dist[5001];
vector<pair<int, int>> adj[5001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) dist[i] = 987654321;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    cin >> s >> t;
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        auto [cost, x] = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x] < cost) continue;
        for(auto [nx, nc] : adj[x]){
            nc += cost;
            if(dist[nx] < nc) continue;
            dist[nx] = nc;
            pq.push({-nc, nx});
        }
    }
    cout << dist[t];
}