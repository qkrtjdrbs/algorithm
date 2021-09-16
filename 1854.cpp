#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int n, m, k, dist[1001][101], Visit[1001];
vector<pair<int, int>> adj[1001];

void dijk(int start){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k;j++)
            dist[i][j] = MAX;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start][1] = 0;
    while(!pq.empty()){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        if(Visit[cur]++ >= k) continue;
        int cnt = Visit[cur];
        cost = -cost;
        dist[cur][cnt] = cost;
        for(auto next : adj[cur]){
            int nextC, nextV;
            tie(nextC, nextV) = next; 
            if(Visit[nextV] <= k)
                pq.push({-dist[cur][cnt]-nextC, nextV});
        }
    }
    for(int i=1;i<=n;i++){
        if(dist[i][k] == MAX) cout << -1;
        else cout << dist[i][k];
        cout << '\n';
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({l, b});
    }
    dijk(1);
}