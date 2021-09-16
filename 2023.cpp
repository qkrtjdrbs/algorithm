#include <bits/stdc++.h>
using namespace std;
int n, m, parent[200001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return false;
    else if(x < y) parent[y] = x;
    else parent[x] = y;
    return true;
}

int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(0);
    while(1){
        cin >> n >> m;
        if(!n && !m) break;
        for(int i=1;i<=n;i++)
            parent[i] = i;
        priority_queue<tuple<int, int, int>> pq;
        int sum = 0, ans = 0;
        for(int i=0;i<m;i++){
            int x, y, z;
            cin >> x >> y >> z;
            sum += z;
            pq.push({-z, x, y});
        }
        while(!pq.empty()){
            int cost, x, y;
            tie(cost, x, y) = pq.top();
            pq.pop();
            cost = -cost;
            if(Union(x, y)) ans += cost;
        }
        for(int i=1;i<=n;i++)
            parent[i] = i;
        cout << sum - ans << '\n';
    }
}
