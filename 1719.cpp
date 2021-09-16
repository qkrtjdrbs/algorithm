#include <bits/stdc++.h>
using namespace std;
int n, m, Map[201][201], dist[201], p[201];
vector<pair<int, int>> adj[201];

void Find(int start, int x){
    if(p[x] == start){
        cout << x << " ";
        return;
    }
    Find(start, p[x]);
}

void dijk(int x){
    for(int i=1;i<=n;i++){
        if(x == i) dist[i] = 0;
        else dist[i] = 987654321;
        p[i] = i;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, x});
    while(!pq.empty()){
        int cur, cost;
        tie(cost, cur) = pq.top();
        pq.pop();
        cost = -cost;
        for(auto next : adj[cur]){
            int newCost, nextV;
            tie(newCost, nextV) = next;
            if(dist[nextV] > newCost + cost){
                dist[nextV] = newCost + cost;
                pq.push({-(newCost+cost), nextV});
                p[nextV] = cur;
            }
        }
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, cost;
        cin >> a >> b >> cost;
        adj[a].push_back({cost, b});
        adj[b].push_back({cost, a});
    }
    for(int i=1;i<=n;i++){
        p[i] = i;
    }
    for(int i=1;i<=n;i++){
        dijk(i);
        for(int j=1;j<=n;j++){
            if(i == j) cout << '-' << " ";
            else Find(i, j);
        }
        cout << '\n';
    }
}