#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m;
ll dist[100001];
bool sight[100001];
vector<pair<int, int>> adj[100001];

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n;i++) cin >> sight[i];
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=0;i<n;i++) dist[i] = LLONG_MAX;
    priority_queue<pair<ll, int>> pq;
    pq.push({0, 0});
    dist[0] = 0;
    while(!pq.empty()){
        ll cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur] < cost) continue;
        for(auto next : adj[cur]){
            ll nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(dist[nx] <= nc) continue;
            if(nx != n-1){
                if(sight[nx]) continue;
                dist[nx] = nc;
                pq.push({-nc, nx});
            } else {
                dist[nx] = nc;
                pq.push({-nc, nx});
            }
        }
    }
    cout << (dist[n-1] == LLONG_MAX ? -1 : dist[n-1]);
}