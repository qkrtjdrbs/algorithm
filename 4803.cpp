#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> adj[501];
bool visited[501], finished[501], cycle;

void dfs(int x, int prev){
    visited[x] = 1;
    for(auto next : adj[x]){
        if(!visited[next]) dfs(next, x);
        else {
            if(next != prev && !finished[next]) cycle = true;
        }
    }
    finished[x] = 1;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    for(int t=1;;t++){
        cin >> n >> m;
        if(!n && !m) break;
        memset(visited, 0, sizeof(visited));
        memset(finished, 0, sizeof(finished));
        for(int i=1;i<=500;i++) adj[i].clear();

        for(int i=0;i<m;i++){
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        int ans = 0;
        for(int i=1;i<=n;i++){
            cycle = false;
            if(!visited[i]){
                dfs(i, -1);
                if(!cycle) ans++;
            } 
        }
        cout << "Case " << t << ": ";
        if(ans > 1) cout << "A forest of " << ans << " trees.\n";
        else if(ans == 1) cout << "There is one tree.\n";
        else cout << "No trees.\n";
    }
}