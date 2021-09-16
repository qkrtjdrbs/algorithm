#include <bits/stdc++.h>
using namespace std;

int n, m, s, e, money[101], parent[101], dist[101];
bool finished[101], visited[101];
vector<pair<int, int>> adj[101];

void dijk(int start, int end){
    priority_queue<pair<int, int>> pq;
    pq.push({money[start], start});
    dist[start] = money[start];

    while(!pq.empty()){
        
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> s >> e >> m;
    memset(dist, -1, sizeof(dist));
    for(int i=0;i<n;i++) parent[i] = i;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
    }
    for(int i=0;i<n;i++) cin >> money[i];
    dijk(s, e);
}