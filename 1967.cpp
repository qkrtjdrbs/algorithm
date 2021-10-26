#include <bits/stdc++.h>
using namespace std;

int n, dist[10001];
bool visited[10001];
vector<pair<int, int>> adj[10001];

int bfs(int start){
    queue<pair<int, int>> q;
    q.push({start, 0});
    visited[start] = 1;
    while(!q.empty()){
        int x, cost;
        tie(x, cost) = q.front();
        q.pop();
        for(auto next : adj[x]){
            int nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(!visited[nx]){
                q.push({nx, nc});
                dist[nx] = nc;
                visited[nx] = 1;
            }
        }
    }
    int mx = -1, res;
    for(int i=1;i<=n;i++){
        if(mx < dist[i]){
            mx = dist[i]; res = i;
        }
    }
    return res;
}


int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int start = bfs(1);
    memset(visited, 0, sizeof(visited));
    memset(dist, 0, sizeof(dist));
    cout << dist[bfs(start)];
}