#include <bits/stdc++.h>
using namespace std;

int n, m, s, e;
vector<pair<int, int>> adj[1001];
vector<int> width;

bool go(int limit){
    bool visited[1001];
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(s);
    visited[s] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        if(cur == e) return true;
        for(auto next : adj[cur]){
            auto [nx, nc] = next;
            if(nc >= limit && !visited[nx]){
                visited[nx] = 1;
                q.push(nx);
            }            
        }
    }
    return false;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m >> s >> e;
    for(int i=0;i<m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        width.push_back(c);
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    sort(width.begin(), width.end());
    int l=0, r=width.size()-1, ans=width[0];
    while(l <= r){
        int mid = (l + r) / 2;
        if(go(width[mid])){
            l = mid + 1;
            ans = max(ans, width[mid]);
        } else {
            r = mid - 1;
        }
    }
    cout << ans;
}