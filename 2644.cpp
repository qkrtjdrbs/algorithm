#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, visited[101], parent[101];
vector<int> adj[101];

void go1(int i){
    visited[i] = 1;
    if(!parent[i]){
        return;
    }
    go1(parent[i]);
}

int go2(int i){
    if(visited[i]) return i;
    if(!parent[i]) return -987654321;
    return go2(parent[i]);
}

int go3(int start){
    memset(visited, 0, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = 1;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(auto next : adj[cur]){
            q.push(next);
            visited[next] = visited[cur] + 1;
        }
    }
    return visited[x] + visited[y] - 2;
}

int main(){
    cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(0);
    cin >> n >> x >> y >> m;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        parent[b] = a;
        adj[a].push_back(b);
    }
    go1(x);
    int root = go2(y);
    if(root < 0){
        cout << -1;
        return 0;
    }
    cout << go3(root);
}