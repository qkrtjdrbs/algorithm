#include <bits/stdc++.h>
using namespace std;
int n, m, v1, v2, dist[801];
vector<pair<int, int>> adj[200001];

void initDist(){
    for(int i=1;i<=n;i++){
        dist[i] = 987654321;
    }
}

long long dijk(int start, int end){
    initDist();
    priority_queue<pair<int ,int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        auto [cost, cur] = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur] < cost) continue;
        for(auto [next, nc] : adj[cur]){
            nc += cost;
            if(dist[next] <= nc) continue;
            dist[next] = nc;
            pq.push({-nc, next});
        }
    }
    return dist[end];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        adj[from].push_back({to, cost});
        adj[to].push_back({from, cost});
    }
    cin >> v1 >> v2;
    long long ans1 = dijk(1, v1) + dijk(v1, v2) + dijk(v2, n);
    long long ans2 = dijk(1, v2) + dijk(v2, v1) + dijk(v1, n);
    long long ans = min(ans1, ans2);
    cout << (ans >= 987654321 ? -1 : ans);
}