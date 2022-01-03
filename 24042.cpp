#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
vector<pair<int, ll>> adj[100001];
ll dist[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
    }
    for(int i=1;i<=n;i++) dist[i] = LLONG_MAX;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        ll cost, x;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x] < cost) continue;
        for(auto next : adj[x]){
            ll nx, period;
            tie(nx, period) = next;
            ll nc = period - (cost % m);
            if(nc < 0) nc += m;
            nc += cost + 1;
            if(dist[nx] > nc){
                dist[nx] = nc;
                pq.push({-nc, nx});
            }
        }
    }
    cout << dist[n];
}