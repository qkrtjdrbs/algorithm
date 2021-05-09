#include <bits/stdc++.h>
#define MAX 987654321
using namespace std;
int t, n, dist[10001];
vector<pair<int, int>> route[10001];

void dijk(int start){
    for(int i=1;i<=n;i++){
        dist[i] = MAX;
    }
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int cost, cur;
        tie(cost, cur) = pq.top();
        pq.pop();
        cost = -cost;
        for(auto next : route[cur]){
            int c, v, newDist;
            tie(c, v) = next;
            newDist = c + cost;
            if(dist[v] > newDist){
                dist[v] = newDist;
                pq.push({-newDist, v});
            }
        }
    }
    int cnt = 0, maxTime = 0;
    for(int i=1;i<=n;i++){
        route[i].clear();
        if(dist[i] != MAX){
            ++cnt;
            maxTime = max(maxTime, dist[i]);
        }
    }
    cout << cnt << " " << maxTime << '\n';
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> t;
    while(t--){
        int d, c;
        cin >> n >> d >> c;
        for(int i=0;i<d;i++){
            int a, b, s;
            cin >> a >> b >> s;
            route[b].push_back({s, a});
        }
        dijk(c);
    }
}