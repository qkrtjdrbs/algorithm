#include <bits/stdc++.h>
using namespace std;

int n, parent[3001];

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(x > y) parent[x] = y;
    else parent[y] = x;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    int t; cin >> t;
    while(t--){
        cin >> n;
        for(int i=0;i<3000;i++) parent[i] = i;
        vector<tuple<int, int, int>> v(n);
        for(int i=0;i<n;i++){
            int x, y, r;
            cin >> x >> y >> r;
            v[i] = {x, y, r};
        }
        for(int i=0;i<n;i++){
            int x1, y1, r1;
            tie(x1, y1, r1) = v[i];
            for(int j=i+1;j<n;j++){
                int x2, y2, r2;
                tie(x2, y2, r2) = v[j];
                if(pow(abs(x1 - x2), 2) + pow(abs(y1 - y2), 2) <= pow(r1 + r2, 2)) Union(i, j);
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(parent[i] == i) ans++;
        }
        cout << ans << '\n';
    }
}