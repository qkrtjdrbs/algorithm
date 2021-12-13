#include <bits/stdc++.h>
using namespace std;

int n, m;
bool visited[101];
vector<int> adj[101];

void bfs(){
    queue<int> q;
    q.push(1);
    visited[1] = 1;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(auto next : adj[x]){
            if(!visited[next]){
                q.push(next);
                visited[next] = 1;
            }
        }
    }
    int res = 0;
    for(int i=2;i<=n;i++){
        if(visited[i]) res++;
    }
    cout << res;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    bfs();
}