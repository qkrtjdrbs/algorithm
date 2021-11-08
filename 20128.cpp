#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll INF = LLONG_MAX;
int n, m;
ll dist[100001][2];
vector<pair<int, int>> adj[100001];


int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<2;j++) dist[i][j] = INF;
    }
    priority_queue<tuple<ll, int>> pq;
    pq.push({0, 1});
    dist[1][0] = 0;
    while(!pq.empty()){
        ll cost; int x;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        bool flag = cost % 2;
        if(dist[x][flag] < cost) continue;
        for(auto next : adj[x]){
            int nx; ll nc; bool nf;
            tie(nx, nc) = next;
            nc += cost;
            nf = nc % 2;
            if(dist[nx][nf] >= nc){
                dist[nx][nf] = nc;
                pq.push({-nc, nx});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j>=0;j--){
            dist[i][j] == INF ? cout << -1 : cout << dist[i][j];
            cout << " ";
        }
        cout << '\n';
    }
}