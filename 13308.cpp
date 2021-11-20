#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, oil[2501];
vector<pair<int, int>> adj[2501];
ll dist[2501][2501];

void dijk(int start){
    ll tmp[2501];
    for(int i=1;i<=n;i++) tmp[i] = LLONG_MAX;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, start});
    tmp[start] = 0;
    while(!pq.empty()){
        ll cost, x;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(tmp[x] < cost) continue;
        for(auto next : adj[x]){
            ll nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(tmp[nx] > nc){
                pq.push({-nc, nx});
                tmp[nx] = nc;
            }
        }
    }
    for(int i=1;i<=n;i++) dist[start][i] = tmp[i];
}

void solve(){
    ll tmp[2501];
    for(int i=1;i<=n;i++) tmp[i] = LLONG_MAX;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    tmp[1] = 0;
    while(!pq.empty()){
        ll cost, x;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(tmp[x] < cost) continue;
        for(int i=1;i<=n;i++){
            ll nc = cost + oil[x] * dist[x][i];
            if(tmp[i] > nc){
                pq.push({-nc, i});
                tmp[i] = nc;
            }
        }
    }
    cout << tmp[n];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> oil[i];
    for(int i=1;i<=m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=1;i<=n;i++) dijk(i);
    solve();
}