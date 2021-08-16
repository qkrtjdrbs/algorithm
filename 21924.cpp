#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, m, sum, ans, conn, parent[100001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y, int c){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(x >= y) parent[x] = y;
    else parent[y] = x;
    ans += c;
    conn += 1;
}

int main(){
    priority_queue<tuple<int, int, int>> pq;
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        sum += c;
        pq.push({-c, a, b});
    }
    while(!pq.empty()){
        if(conn == n-1) break;
        int a, b, c;
        tie(c, a, b) = pq.top();
        pq.pop();
        c = -c;
        Union(a, b, c);
    }
    if(conn < n-1){
        cout << -1;
        return 0;
    }
    int tmp = parent[1];
    for(int i=2;i<=n;i++){
        if(parent[Find(i)] != tmp) {
            cout << -1;
            return 0;
        }
    }
    cout << sum - ans;
}