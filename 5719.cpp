#include <bits/stdc++.h>
using namespace std;

int n, m, s, d, dist[501];
vector<pair<int, int>> adj[501];
vector<int> shortest[501];

void dijk(){
    priority_queue<pair<int, int>> pq;
    pq.push({0, s});
    dist[s] = 0;
    while(!pq.empty()){
        int cost, x;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(cost > dist[x]) continue;
        for(int i=0;i<adj[x].size();i++){
            int nx, nc;
            tie(nx, nc) = adj[x][i];
            nc += cost;
            if(adj[x][i].second){
                if(dist[nx] > nc){
                    pq.push({-nc, nx});
                    dist[nx] = nc;
                    shortest[nx].clear();
                    shortest[nx].push_back(x);
                } else if(dist[nx] == nc){
                    shortest[nx].push_back(x);
                }
            }
        }
    }
}

void deletePath(){
    queue<int>q;
    q.push(d);
    bool check[501] = {0,};
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(check[x] == true) continue;
        for(int i=0; i<shortest[x].size();i++) {
            int nx = shortest[x][i];
            for(int j=0;j<adj[nx].size();j++) {
                if(adj[nx][j].first == x) adj[nx][j].second = 0;
            }
            q.push(nx);
        }
        check[x] = true;
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    while(1){
        cin >> n >> m;
        if(!n && !m) break;
        cin >> s >> d;
        for(int i=0;i<=500;i++) {
            shortest[i].clear();
            adj[i].clear();
        }
        for(int i=0;i<=n;i++) dist[i] = 987654321;
        for(int i=0;i<m;i++){
            int a, b, c;
            cin >> a >> b >> c;
            adj[a].push_back({b, c});
        }
        dijk();
        deletePath();
        for(int i=0;i<=n;i++) dist[i] = 987654321;
        dijk();
        dist[d] == 987654321 ? cout << -1 : cout << dist[d];
        cout << '\n';
    }
}