#include <bits/stdc++.h>
using namespace std;

int n, m, dist[4001][2][2];
vector<pair<int, int>> adj[4001];

void dijk(bool wolf){
    for(int i=1;i<=n;i++){
        dist[i][wolf][0] = dist[i][wolf][1] = INT_MAX;
    }
    priority_queue<tuple<int, int, bool>> pq;
    if(wolf){
        pq.push({0, 1, 1});
    } else {
        pq.push({0, 1, 0});
        dist[1][0][0] = 0;
    }
    while(!pq.empty()){
        int cost, x, fast;
        tie(cost, x, fast) = pq.top();
        pq.pop();
        cost = -cost;
        if(wolf && dist[x][wolf][!fast] < cost) continue;
        if(!wolf && dist[x][wolf][0] < cost) continue;
        for(auto next : adj[x]){
            int nc, nx;
            tie(nx, nc) = next;
            if(wolf){
                if(fast) nc /= 2;
                else nc *= 2;
            }
            nc += cost;
            if(dist[nx][wolf][fast] <= nc) continue;
            if(wolf){
                pq.push({-nc, nx, !fast});
                dist[nx][wolf][fast] = nc;
            } else {
                pq.push({-nc, nx, 0});
                dist[nx][wolf][0] = nc;
            }
        }
    }   
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, 2*c});
        adj[b].push_back({a, 2*c});
    }
    dijk(0); dijk(1);
    int ans = 0;
    for(int i=2;i<=n;i++){
        if(dist[i][0][0] < min(dist[i][1][0], dist[i][1][1])) ans++;
    }
    cout << ans;
}