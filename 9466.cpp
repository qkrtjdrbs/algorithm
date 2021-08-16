#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100001];
int ans, parent[100001], finished[100001], visited[100001];

void dfs(int cur)
{
    visited[cur] = true;
    for (auto next : adj[cur]) {
        if (!visited[next]) {
            parent[cur] = next;
            dfs(next);
        }
        else if (finished[next] == false) {
            for(int i=next;i!=cur;i=parent[i]) ans++;
            ans++;
        }
    }
    finished[cur] = true;
}

void init(){
    ans = 0;
    memset(parent, 0, sizeof(parent));
    memset(visited, 0, sizeof(visited));
    memset(finished, 0, sizeof(finished));
    for(int i=0;i<100001;i++){
        adj[i].clear();
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    cin >> t;
    while(t--){
        init();
        int n;
        cin >> n;
        for(int i=1;i<=n;i++){
            int next;
            cin >> next;
            adj[i].push_back(next);
        }
        for(int i=1;i<=n;i++){
            if(!visited[i]) dfs(i);
        }
        cout << n-ans << '\n';
    }
}