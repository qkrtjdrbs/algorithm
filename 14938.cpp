#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int n, m, r, item[101], dist[101];
vector<pair<int, int>> adj[101];

int dijk(int start){
    for(int i=1;i<=n;i++)
        dist[i] = MAX;
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur] > cost)
            dist[cur] = cost;
        for(auto next : adj[cur]){
            int nextC, nextV;
            tie(nextC, nextV) = next;
            if(dist[nextV] > nextC + cost){
                pq.push({-(nextC + cost), nextV});
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] <= m)
            res += item[i];
    }
    return res;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> r;
    for(int i=1;i<=n;i++){
        cin >> item[i];
    }
    for(int i=1;i<=r;i++){
        int a, b, l;
        cin >> a >> b >> l;
        adj[a].push_back({l, b});
        adj[b].push_back({l, a});
    }
    int ans = 0;
    for(int i=1;i<=n;i++){
        ans = max(ans, dijk(i));
    }
    cout << ans;
}