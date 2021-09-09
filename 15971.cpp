#include <bits/stdc++.h>
using namespace std;

int n, a, b, ans=987654321, distA[100001], distB[100001];
bool visited[100001];
vector<pair<int, int>> adj[100001];

void dijk(){
    priority_queue<tuple<int, int, bool>> pq;
    pq.push({0, a, 1});
    pq.push({0, b, 0});
    distA[a] = 0; distB[b] = 0;
    while(!pq.empty()){
        int cost, cur, flag;
        tie(cost, cur, flag) = pq.top();
        pq.pop();
        cost = -cost;
        for(auto next : adj[cur]){
            int nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(flag && distA[nx] > nc){
                distA[nx] = nc;
                pq.push({-nc, nx, 1});
            } else if(!flag && distB[nx] > nc){
                distB[nx] = nc;
                pq.push({-nc, nx, 0});
            }
        }
    }
}

void dfs(int x){
    visited[x] = 1;
    ans = min(ans, distA[x]+distB[x]);
    for(auto next : adj[x]){
        int nx, nc;
        tie(nx, nc) = next;
        if(!visited[nx]){
            ans = min(ans, min(distA[nx]+distB[x], distA[x]+distB[nx]));
            dfs(nx);
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> a >> b;
    fill(distA, distA+n+1, 987654321);
    fill(distB, distB+n+1, 987654321);
    for(int i=0;i<n-1;i++){
        int x, y, d;
        cin >> x >> y >> d;
        adj[x].push_back({y, d});
        adj[y].push_back({x, d});
    }
    dijk();
    dfs(1);
    cout << ans;
}