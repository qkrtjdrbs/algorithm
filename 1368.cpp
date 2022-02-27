#include <bits/stdc++.h>
using namespace std;

int n, ans, w[301], p[301][301], parent[301];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(x < y) parent[x] = y;
    else parent[y] = x;
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    priority_queue<tuple<int, int, int>> pq;
    for(int i=0;i<=n;i++) parent[i] = i;
    for(int i=0;i<n;i++){
        cin >> w[i];
        pq.push({-w[i], i, n});
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> p[i][j];
            pq.push({-p[i][j], i, j});
        }
    }
    while(!pq.empty()){
        auto [cost, x, y] = pq.top();
        pq.pop();
        if(Union(x, y)){
            ans -= cost;
        }
    }
    cout << ans;
}