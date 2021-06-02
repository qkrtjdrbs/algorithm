#include <bits/stdc++.h>
using namespace std;
int n, m, k, ans, parent[1001], plant[1001];
priority_queue<tuple<int, int, int>> pq;

int Find(int x){
    if(x == parent[x]) return x;
    return parent[x] = Find(parent[x]);
}

void Union(int x, int y, int c){
    x = Find(x);
    y = Find(y);
    if(x == y) return;
    if(!plant[x] && !plant[y]){
        if(x > y) parent[x] = y;
        else parent[y] = x;
    } else if(plant[x] && plant[y]){
        return;
    } else if(plant[x]){
        parent[y] = x;
    } else if(plant[y]){
        parent[x] = y;
    }
    ans += c;
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> m >> k;
    for(int i=1;i<=n;i++){
        parent[i] = i;
    }
    for(int i=0;i<k;i++){
        int x;
        cin >> x;
        plant[x] = 1;
    }
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        pq.push({-c, a, b});
    }
    while(!pq.empty()){
        bool flag = false;
        for(int i=1;i<=n;i++){
            if(!plant[Find(i)]){
                flag = true;
                break;
            }
        }
        if(!flag) break;
        int cost, x, y;
        tie(cost, x, y) = pq.top();
        pq.pop();
        Union(x, y, -cost);
    }
    cout << ans;
}