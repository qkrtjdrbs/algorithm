#include <bits/stdc++.h>
using namespace std;
int n, m, v1, v2, dist[801];
vector<pair<int, int>> M[200001];

void initDist(){
    for(int i=1;i<=n;i++){
        dist[i] = 987654321;
    }
}

int dijk(int start, int end){
    if(start == end) return 0;
    initDist();
    priority_queue<pair<int ,int>> pq;
    pq.push({0, start});
    while(!pq.empty()){
        int cost, vertex;
        tie(cost, vertex) = pq.top();
        cost *= -1;
        if(cost == 987654321) return -cost;
        pq.pop();
        if(vertex == end) break;
        for(auto i : M[vertex]){
            int toV, newC;
            tie(toV, newC) = i;
            if(dist[toV] > cost + newC){
                dist[toV] = cost + newC;
                pq.push({-(cost+newC), toV});
            }
        }
    }
    return dist[end];
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        M[from].push_back({to, cost});
        M[to].push_back({from, cost});
    }
    cin >> v1 >> v2;
    int ans1 = dijk(1, v1) + dijk(v1, v2) + dijk(v2, n);
    int ans2 = dijk(1, v2) + dijk(v2, v1) + dijk(v1, n);
    int ans = min(ans1, ans2);
    if(ans < 0) ans = -1;
    cout << ans;
}