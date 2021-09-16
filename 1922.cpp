#include <bits/stdc++.h>
using namespace std;
int n, m, visit[1001];
vector<pair<int, int>> M[1001];

int dijk(){
    int res = 0;
    priority_queue<pair<int, int>> pq;
    pq.push({0, 1});
    while(!pq.empty()){
        int cost, vertex;
        tie(cost, vertex) = pq.top();
        pq.pop();
        cost *= -1;
        if(!visit[vertex]){
            visit[vertex] = 1;
            res += cost;
            for(auto x : M[vertex]){
                int newCost, newVertex;
                tie(newVertex, newCost) = x;
                if(!visit[newVertex]){
                    pq.push({-newCost, newVertex});
                }
            }
        }
    }
    return res;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        M[a].push_back({b, c});
        M[b].push_back({a, c});
    }
    int ans = dijk();
    cout << ans;
}