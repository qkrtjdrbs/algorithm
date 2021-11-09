#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;

int n, m, x, y, dist[10001], mDist[10001], sDist[10001];
bool notHome[10001];
vector<pair<int, int>> adj[10001];
vector<int> mdn, sbk;

void dijk(vector<int> v){
    for(int i=0;i<=n;i++) dist[i] = MAX;
    priority_queue<pair<int, int>> pq;
    for(auto i : v){
        pq.push({0, i});
        dist[i] = 0;
    }
    while(!pq.empty()){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[cur] < cost) continue;
        for(auto next : adj[cur]){
            int nx, nc;
            tie(nx, nc) = next;
            nc += cost;
            if(dist[nx] > nc){
                pq.push({-nc, nx});
                dist[nx] = nc;
            }
        }
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    int mc; cin >> mc >> x;
    for(int i=0;i<mc;i++){
        int idx; cin >> idx;
        notHome[idx] = 1;
        mdn.push_back(idx);
    }
    int st; cin >> st >> y;
    for(int i=0;i<st;i++){
        int idx; cin >> idx;
        notHome[idx] = 1;
        sbk.push_back(idx);
    }
    dijk(mdn);
    memcpy(mDist, dist, sizeof(dist));
    dijk(sbk);
    memcpy(sDist, dist, sizeof(dist));
    int ans = MAX;
    for(int i=1;i<=n;i++){
        if(notHome[i]) continue;
        if(mDist[i] <= x && sDist[i] <= y){
            ans = min(ans, mDist[i]+sDist[i]);
        }
    }
    ans == MAX ? cout << -1 : cout << ans;
}