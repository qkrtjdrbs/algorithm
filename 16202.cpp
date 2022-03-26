#include <bits/stdc++.h>
using namespace std;

int n, m, k, parent[1001];
vector<tuple<int, int, int>> v;

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

int mst(int start){
    for(int i=1;i<=n;i++) parent[i] = i;
    priority_queue<tuple<int, int, int>> pq;
    for(int i=start;i<m;i++){
        auto [a, b, c] = v[i];
        pq.push({-c, a, b});
    }
    int sum = 0;
    while(!pq.empty()){
        auto [c, a, b] = pq.top();
        pq.pop();
        c = -c;
        if(Union(a, b)) sum += c;
    }
    for(int i=1;i<=n;i++){
        if(Find(i) != 1) return -1;
    }
    return sum;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        v.push_back({a, b, i});
    }
    bool flag = false;
    for(int i=0;i<k;i++){
        if(flag) cout << 0 << " ";
        else {
            int res = mst(i);
            if(res == -1){
                cout << 0 << " ";
                flag = true;
            } else cout << res << " ";
        }
    }
}