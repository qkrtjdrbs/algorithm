#include <bits/stdc++.h>
using namespace std;

int n, m, t, parent[10001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x); y = Find(y);
    if(x == y) return false;
    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> t;
    for(int i=1;i<=n;i++) parent[i] = i;

    priority_queue<tuple<int, int, int>> pq;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    int ans = 0;
    while(!pq.empty()){
        int cost, a, b;
        tie(cost, a, b) = pq.top();
        pq.pop();
        cost = -cost;
        if(Union(a, b)) ans += cost;
    }
    cout << ans + (n-1)*(n-2)*t/2;
}