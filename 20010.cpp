#include <bits/stdc++.h>
using namespace std;

int n, k, minCost, parent[1001], dist[1001];
vector<pair<int, int>> adj[1001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

int longest(int sx, bool isVertex){
    int maxDist = 0, v = sx;
    for(int i=0;i<n;i++) dist[i] = INT_MAX;
    priority_queue<pair<int, int>> pq;
    pq.push({0, sx});
    dist[sx] = 0;
    while(!pq.empty()){
        int x, cost;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x] < cost) continue;
        for(auto next : adj[x]){
            int nx, nc;
            tie(nc, nx) = next;
            if(dist[nx] > cost + nc){
                dist[nx] = cost + nc;
                pq.push({-(cost+nc), nx});
            }
        }
    }
    for(int i=0;i<n;i++){
        if(dist[i] > maxDist){
            maxDist = dist[i];
            v = i;
        }
    }
    if(isVertex)
        return v;
    else return maxDist;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    priority_queue<tuple<int, int, int>> pq;
    cin >> n >> k;
    for(int i=0;i<n;i++) parent[i] = i;
    for(int i=0;i<k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    while(!pq.empty()){
        int a, b, c;
        tie(c, a, b) = pq.top();
        pq.pop();
        c = -c;
        if(Union(a, b)){
            adj[a].push_back({c, b});
            adj[b].push_back({c, a});
            minCost += c;
        }
    }
    cout << minCost << '\n';
    int start = longest(0, 1);
    cout << longest(start, 0);
}