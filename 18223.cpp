#include <bits/stdc++.h>
using namespace std;

int n, m, p;
bool visited[5001];
vector<pair<int, int>> adj[5001];

int dijk(int start, int end){
    int dist[5001];
    for(int i=1;i<=n;i++) dist[i] = 987654321;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cost, x;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x] < cost) continue;
        for(auto next : adj[x]){
            int nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(dist[nx] > nc){
                dist[nx] = nc;
                pq.push({-nc, nx});
            }
        }
    }
    return dist[end];
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> p; 
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    dijk(1, p) + dijk(p, n) == dijk(1, n) ? cout << "SAVE HIM" : cout << "GOOD BYE";
}