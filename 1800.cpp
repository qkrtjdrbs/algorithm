#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int n, m, k, dist[1001][1001];
vector<pair<int, int>> adj[1001];

void dijk(){
    priority_queue<tuple<int, int, int>> pq;
    pq.push({0, 0, 1});
    dist[1][0] = 0;
    while(!pq.empty()){
        auto [cost, dc, cur] = pq.top();
        pq.pop();
        cost = -cost;
        for(auto [next, nc] : adj[cur]){
            nc = max(nc, cost);
            if(dc < k){
                if(dist[next][dc+1] > cost){
                    dist[next][dc+1] = cost;
                    pq.push({-cost, dc+1, next});
                }
            }
            if(dist[next][dc] > nc){
                dist[next][dc] = nc;
                pq.push({-nc, dc, next});
            }
        }
    }
    int ans = MAX;
    for(int i=0;i<=k;i++){
        ans = min(ans, dist[n][i]);
    }
    cout << (ans == MAX ? -1 : ans);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<=k;j++) dist[i][j] = MAX;
    }
    dijk();
}