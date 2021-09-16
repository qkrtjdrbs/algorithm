#include <bits/stdc++.h>
using namespace std;
int n, m, dist[10001];
vector<pair<int, int>> adj[10001];

int dijk(int start, int end){
    priority_queue<pair<int, int>> pq;
    pq.push({1000000000, start});
    dist[start] = 1000000000;
    while(!pq.empty()){
        int x, cost;
        tie(cost, x) = pq.top();
        pq.pop();
        if(cost < dist[x]) continue;
        for(auto next : adj[x]){
            int nx, nc;
            tie(nx, nc) = next;
            if(dist[nx] < min(cost, nc)){
                dist[nx] = min(cost, nc);
                pq.push({dist[nx], nx});
            }
        }
    }
    return dist[end];
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int s, e;
    cin >> s >> e;
    cout << dijk(s, e);
}