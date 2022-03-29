#include <bits/stdc++.h>
using namespace std;

int n, t;
vector<int> adj[200001];
set<pair<int, int>> visited;

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> t;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        adj[y].push_back(x);
    }
    for(int i=0;i<=200000;i++) sort(adj[i].begin(), adj[i].end());
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 0});
    visited.insert({0, 0});
    while(!q.empty()){
        auto [x, y, c] = q.front();
        q.pop();
        if(y == t){
            cout << c;
            return 0;
        }
        for(int ny=max(0, y-2);ny<=min(200000, y+2);ny++){
            for(auto nx : adj[ny]){
                if(x - nx > 2) continue;
                if(nx - x > 2) break;
                if(visited.find({nx, ny}) != visited.end()) continue;
                q.push({nx, ny, c+1});
                visited.insert({nx, ny});
            }
        }
    }
    cout << -1;
}