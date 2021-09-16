#include <bits/stdc++.h>
using namespace std;
int n, m, edges, dist[1001], parent[1001];

priority_queue<tuple<int, int, int>> pq;
vector<pair<int, int>> ans;
vector<pair<int, int>> adj[1001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    int nx = Find(x);
    int ny = Find(y);
    if(nx == ny) return;
    if(nx > ny) parent[nx] = ny;
    else parent[ny] = nx;
    edges++;
    ans.push_back({x, y});
}

void dijk(){
    for(int i=1;i<=1000;i++)
        dist[i] = 987654321;
    priority_queue<tuple<int, int, int>> pq;
    dist[1] = 0;
    pq.push({0, 1, -1});
    while(!pq.empty()){
        int cost, x, px;
        tie(cost, x, px) = pq.top();
        pq.pop();
        cost = -cost;
        if(px != -1){
            Union(x, px);
        }
        for(auto next : adj[x]){
            int nx = next.first;
            int nc = next.second + cost;
            if(dist[nx] > nc){
                dist[nx] = nc;
                pq.push({-nc, nx, x});
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        parent[i] = i;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijk();
    cout << ans.size() << '\n';
    for(auto i : ans){
        cout << i.first << " " << i.second << '\n';
    }
}