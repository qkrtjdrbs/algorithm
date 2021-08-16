#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, parent[100001], visited[100001];
vector<pair<int, int>> adj[100001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y, int c){
    int px = Find(x);
    int py = Find(y);
    if(px == py) return;
    if(px > py) parent[px] = py;
    if(px < py) parent[py] = px;
    adj[x].push_back({c, y});
    adj[y].push_back({c, x});
}

int main() {
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    priority_queue<tuple<int, int, int>> pq;
	cin >> n >> m >> s >> e;
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({c, a, b});
    }
    while(!pq.empty()){
        int a, b, c;
        tie(c, a, b) = pq.top();
        pq.pop();
        Union(a, b, c);
    }
    visited[s] = 987654321;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(x == e) break;
        for(auto next : adj[x]){
            int nx, nc;
            tie(nc, nx) = next;
            if(!visited[nx]){
                visited[nx] = min(visited[x], nc);
                q.push(nx);
            }
        }
    }
    cout << visited[e];
}