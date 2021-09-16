#include <bits/stdc++.h>
using namespace std;
int n, parent[1000001];
long long ans = 0;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    if(x > y) parent[x] = y;
    else parent[y] = x;
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++) parent[i] = i;
    priority_queue<tuple<int, int, int>> pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            int c;
            cin >> c;
            pq.push({-c, i, j});
        }
    }
    while(!pq.empty()){
        int cost, x, y;
        tie(cost, x, y) = pq.top();
        pq.pop();
        cost = -cost;
        if(Union(x, y)) ans += cost;
    }
    cout << ans;
}