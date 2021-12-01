#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, d, e, height[100001];
ll dist[100001][2];
vector<pair<int, int>> adj[100001];

void dijk(int start, bool flag){
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});
    dist[start][flag] = 0;
    while(!pq.empty()){
        ll cost, x;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x][flag] < cost) continue;
        for(auto next : adj[x]){
            ll nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(height[x] < height[nx] && dist[nx][flag] > nc){
                dist[nx][flag] = nc;
                pq.push({-nc, nx});   
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> d >> e;
    for(int i=0;i<n;i++) cin >> height[i];
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a-1].push_back({b-1, c});
        adj[b-1].push_back({a-1, c});
    }
    for(int i=0;i<=n;i++) dist[i][0] = dist[i][1] = LLONG_MAX;
    dijk(0, 0);
    dijk(n-1, 1);
    ll ans = LLONG_MIN;
    for(int i=1;i<n-1;i++){
        if(dist[i][0] == LLONG_MAX || dist[i][1] == LLONG_MAX) continue;
        ans = max(ans, height[i]*e - dist[i][0]*d - dist[i][1]*d);
    }
    ans == LLONG_MIN ? cout << "Impossible" : cout << ans;
}