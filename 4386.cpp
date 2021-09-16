#include <bits/stdc++.h>
using namespace std;
int n, parent[101];
float ans;
vector<pair<float, float>> v;
priority_queue<tuple<float, int, int>> pq;

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
    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n;i++)
        parent[i] = i;
    for(int i=0;i<n;i++){
        float x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            float dist = sqrt(powf(abs(v[i].first - v[j].first), 2) + powf(abs(v[i].second - v[j].second), 2));
            pq.push({-dist, i, j});
        }
    }
    while(!pq.empty()){
        float d;
        int x, y;
        tie(d, x, y) = pq.top();
        pq.pop();
        d = -d;
        if(Union(x, y)) ans += d;
    }
    printf("%.2f", ans);
}