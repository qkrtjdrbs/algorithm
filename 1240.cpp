#include <bits/stdc++.h>
using namespace std;

int n, m, visited[1001];
vector<pair<int, int>> adj[1001];

void go(int cur, int sum, int end){
    visited[cur] = 1;
    if(end == cur){
        cout << sum << '\n';
        return;
    }
    for(auto next : adj[cur]){
        int nx, nc;
        tie(nx, nc) = next;
        if(!visited[nx]) go(nx, sum+nc, end);
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<n-1;i++){
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        memset(visited, 0, sizeof(visited));
        go(a, 0, b);
    }
}