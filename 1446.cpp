#include <bits/stdc++.h>
using namespace std;

int n, d, dist[10001];
vector<pair<int, int>> adj[10001];

void dijk(){
    for(int i=0;i<=10000;i++) dist[i] = 987654321;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        auto [cost, x] = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x] < cost) continue;
        for(auto [nx, nc] : adj[x]){
            nc += cost;
            if(dist[nx] <= nc) continue;
            pq.push({-nc, nx});
            dist[nx] = nc;
        }
        if(x+1 <= 10000){
            if(dist[x+1] > cost+1){
                pq.push({-(cost+1), x+1});
                dist[x+1] = cost+1;
            }
        }
    }
    cout << dist[d];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> d;
    for(int i=0;i<n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        adj[x].push_back({y, z});
    }
    dijk();
}