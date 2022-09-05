#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, k;
ll dist[100001];
vector<pair<int, ll>> adj[100001];
vector<int> meets;

void dijk(){
    for(int i=1;i<=n;i++) dist[i] = LLONG_MAX;
    priority_queue<pair<ll, int>> pq;
    for(auto meet : meets){
        pq.push({0, meet});
        dist[meet] = 0;
    }
    while(!pq.empty()){
        auto [cost, x] = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x] < cost) continue;
        for(auto [nx, nc] : adj[x]){
            nc += cost;
            if(dist[nx] <= nc) continue;
            dist[nx] = nc;
            pq.push({-nc, nx});
        }
    }
    int ans1 = 987654321;
    ll ans2 = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] > 0 && dist[i] != LLONG_MAX){
            if(ans2 < dist[i]){
                ans2 = dist[i];
                ans1 = i;
            }
        }
    }
    cout << ans1 << '\n' << ans2;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[b].push_back({a, c});
    }
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        meets.push_back(x);
    }
    dijk();
}