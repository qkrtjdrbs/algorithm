#include <bits/stdc++.h>
using namespace std;

int n, m, dist[50001];
vector<pair<int, int>> adj[50001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=1;i<=n;i++) dist[i] = 987654321;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 1;
    while(!pq.empty()){
        int cur, cost;
        tie(cost, cur) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur] < cost) continue;
        for(auto next : adj[cur]){
            int nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(dist[nx] > nc){
                dist[nx] = nc;
                pq.push({-nc, nx});
            }
        }
    }
    cout << dist[n];
}