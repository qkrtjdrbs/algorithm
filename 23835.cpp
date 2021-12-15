#include <bits/stdc++.h>
using namespace std;

int n, q, room[1001], parent[1001];
vector<int> adj[1001];

void dfs(int prev, int cur, int end){
    parent[cur] = prev;
    if(cur == end) return;
    for(auto next : adj[cur]){
        if(next != prev) dfs(cur, next, end);
    }
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    cin >> q;
    for(int i=0;i<q;i++){
        int t, u, v, x;
        cin >> t;
        if(t == 1){
            memset(parent, 0, sizeof(parent));
            cin >> u >> v;
            dfs(0, u, v);
            int cnt = -1;
            for(int i=v;i;i=parent[i],cnt++){
            }
            for(int i=v;i;i=parent[i]){
                room[i] += cnt--;
            }
        } else {
            cin >> x;
            cout << room[x] << '\n';
        }
    }
}