#include <bits/stdc++.h>
using namespace std;
int n, m, ans, parent[1001];
char univ[1001];
priority_queue<tuple<int, int, int>> pq;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y, int d){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(x >= y){
        parent[x] = y;
    } else {
        parent[y] = x;
    }
    ans += d;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> univ[i];
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int u, v, d;
        cin >> u >> v >> d;
        pq.push({-d, u, v});
    }
    while(!pq.empty()){
        int dist, x, y;
        tie(dist, x, y) = pq.top();
        pq.pop();
        dist = -dist;
        if(univ[x] == univ[y]) continue;
        Union(x, y, dist);
    }
    for(int i=1;i<=n;i++){
        Find(i);
    }
    for(int i=1;i<n;i++){
        if(parent[i] != parent[i+1]){
            ans = -1;
            break;
        }
    }
    cout << ans;
}