#include <bits/stdc++.h>
#define MAX 1000000001
using namespace std;

int n, q, dist[5001];
bool visited[5001];
vector<pair<int, int>> adj[5001];

int bfs(int k, int start){
    fill(dist, dist+n+1, MAX);
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int>> q;
    q.push({start, MAX});
    visited[start] = 1;

    while(!q.empty()){
        int cur, cost;
        tie(cur, cost) = q.front();
        q.pop();
        for(auto next : adj[cur]){
            int nx, nc;
            tie(nx, nc) = next;
            if(!visited[nx]){
                dist[nx] = min(nc, cost);
                q.push({nx, dist[nx]});
                visited[nx] = 1;
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(i == start) continue;
        if(dist[i] >= k) res++;
    }
    return res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> q;
    for(int i=0;i<n-1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=0;i<q;i++){
        int k, v;
        cin >> k >> v;
        cout << bfs(k, v) << '\n';
    }
}