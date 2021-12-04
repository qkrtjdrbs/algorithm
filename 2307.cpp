#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int n, m, mn, ans, dist[1001], parent[1001];
vector<pair<int, int>> adj[1001];

int dijk(int a, int b){
    for(int i=1;i<=n;i++) dist[i] = MAX;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    dist[1] = 0;
    while(!pq.empty()){
        int cost, x;
        tie(cost, x) = pq.top();
        cost = -cost;
        pq.pop();
        if(dist[x] < cost) continue;
        for(auto next : adj[x]){
            int nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if((a == x && b == nx) || (a == nx && b == x)) continue;
            if(dist[nx] > nc){
                dist[nx] = nc;
                if(!a && !b) parent[nx] = x;
                pq.push({-nc, nx});
            }
        }
    }
    if(!a && !b) return mn = dist[n];
    return dist[n];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijk(0, 0);
    int ans = 0;
    for(int i=n;i;i=parent[i]){
        ans = max(ans, dijk(i, parent[i]));
    }
    ans == MAX ? cout << -1 : cout << ans - mn;
}