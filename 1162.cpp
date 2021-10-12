#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k;
ll dist[10001][21];
vector<pair<int, int>> adj[10001];

void dijk(){
    for(int i=0;i<=n;i++){
        for(int j=0;j<=k;j++) dist[i][j] = INT64_MAX;
    }
    priority_queue<tuple<ll, ll, ll>> pq;
    pq.push({0, 1, 0});
    dist[1][0] = 0;
    while(!pq.empty()){
        ll cost, cur, cnt;
        tie(cost, cur, cnt) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur][cnt] < cost) continue;
        for(auto next : adj[cur]){
            ll nc, nx;
            tie(nx, nc) = next;
            nc += cost;
            if(cnt + 1 <= k && dist[nx][cnt+1] > cost){
                dist[nx][cnt+1] = cost;
                pq.push({-cost, nx, cnt+1});
            }
            if(dist[nx][cnt] > nc){
                dist[nx][cnt] = nc;
                pq.push({-nc, nx, cnt});
            }
        }
    }
    ll ans = INT64_MAX;
    for(int i=0;i<=k;i++) ans = min(ans, dist[n][i]);
    cout << ans;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijk();
}