#include <bits/stdc++.h>
using namespace std;

int n, dist[51], person[51], minDist=987654321;
vector<int> adj[51];

void dijk(int start){
    priority_queue<pair<int, int>> pq;
    pq.push({0, start});
    dist[start] = 0;
    while(!pq.empty()){
        int x, cost;
        tie(cost, x) = pq.top();
        pq.pop();
        cost = -cost;
        if(dist[x] < cost) continue;
        for(auto next : adj[x]){
            if(dist[next] > cost + 1){
                dist[next] = cost + 1;
                pq.push({-(cost+1), next});
            }
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){
        if(dist[i] != 987654321){
            res = max(res, dist[i]);
        }
    }
    person[start] = res;
    minDist = min(minDist, res);
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    while(1){
        int a, b;
        cin >> a >> b;
        if(a == -1 && b == -1) break;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=1;i<=n;i++){
        for(int i=1;i<=n;i++){
            dist[i] = 987654321;
        }
        dijk(i);
    }
    vector<int> v;
    for(int i=1;i<=n;i++){
        if(person[i] == minDist) v.push_back(i);
    }
    sort(v.begin(), v.end());
    cout << minDist << " " << v.size() << '\n';
    for(auto x : v){
        cout << x << " ";
    }
}